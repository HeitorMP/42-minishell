/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:02:57 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 18:25:33 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	checking_next_node(t_ast **tree)
{
	while ((*tree)->prev)
		*tree = (*tree)->prev;
	while ((*tree)->rigth && is_file((*tree)->type))
		(*tree) = (*tree)->rigth;
}

int	simple_commands(t_root *r, int *status)
{
	pid_t	pid;

	if (checking_redirects(r, status))
		return (*status);
	checking_next_node(&r->tree);
	if (r->tree->type != command || r->tree->command[0] == NULL)
		return (0);
	if (r->tree && r->tree->type == command && !is_built(r->tree->command, 0))
	{
		pid = fork();
		if (pid == 0)
			do_command(r);
		signal(SIGINT, sig_int2);
		signal(SIGQUIT, sig_quit);
		waitpid(pid, status, 0);
	}
	else if (r->tree && r->tree->type == command && \
	is_built(r->tree->command, 0))
		*status = built_in_router(r);
	return (0);
}

void	ending_cleaning(t_ast **tree)
{
	while ((*tree)->prev)
		*tree = (*tree)->prev;
	while (*tree)
	{
		if ((*tree)->type == here_doc)
		{
			unlink(".here_doc");
			break ;
		}
		if (!(*tree)->rigth)
			break ;
		*tree = (*tree)->rigth;
	}
	if ((*tree)->prev)
		while ((*tree)->prev)
			*tree = (*tree)->prev;
}

int	checking_processes(t_root *root)
{
	int		status;

	status = 0;
	if (check_expander(root))
		return (root->status);
	while (root->tree->prev)
		root->tree = root->tree->prev;
	if (!counting_pipes(root->tree))
	{
		simple_commands(root, &status);
		while (root->tree->prev)
			root->tree = root->tree->prev;
		ending_cleaning(&(root->tree));
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else
	{
		status = doing_pipes(root);
		return (status);
	}
	return (status);
}

int	*get_singlequotes(t_root *r, char **split)
{
	int	*a_squotes;

	a_squotes = (int *)malloc(sizeof(int) * r->len);
	while (r->j < r->len)
	{
		if (r->i == r->j)
		{
			while (split[r->a])
			{
				a_squotes[r->j] = r->tree->squotes[r->b];
				r->a++;
				r->j++;
			}
			r->b++;
		}
		else
		{
			a_squotes[r->j] = r->tree->squotes[r->b];
			r->j++;
			r->b++;
		}
	}
	return (a_squotes);
}
