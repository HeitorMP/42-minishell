/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:35:44 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 11:02:39 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	e_pro(char *str, t_ast *node, int error, int type)
{
	write(2, "minishell: ", 11);
	if (node->prev && type == 0)
		write(2, node->file, ft_strlen(node->file));
	else if (node && node->type == command && type == 1)
		write(2, node->command[0], ft_strlen(node->command[0]));
	write(2, " : ", 1);
	write(2, str, ft_strlen(str));
	write(2, "\n\n", 1);
	return (error);
}

int	e_pro_fork(char *str, t_root *r, int error, int type)
{
	write(2, "minishell: ", 11);
	if (r->tree->prev && type == 0)
		write(2, r->tree->file, ft_strlen(r->tree->file));
	else if (r->tree && r->tree->type == command && type == 1)
		write(2, r->tree->command[0], ft_strlen(r->tree->command[0]));
	write(2, " : ", 1);
	write(2, str, ft_strlen(str));
	write(2, "\n\n", 1);
	free_all(r, 1);
	return (error);
}

int	error_syntax(char *str, int error)
{
	write(2, "minishell: ", 11);
	write(2, "syntax error near unexpected token ", 35);
	if (!ft_strncmp(str, "'newline'", 9))
		write(2, str, ft_strlen(str));
	else
		write(2, &str[0], 1);
	write(2, "\n", 1);
	return (error);
}

void	close_fd(t_ast *tree, int *pipes)
{
	int	num_pipes;
	int	i;

	while (tree->prev)
		tree = tree->prev;
	num_pipes = counting_pipes(tree);
	i = 0;
	while (i < num_pipes * 2)
	{
		close(pipes[i]);
		i++;
	}
}

void	free_str_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}
