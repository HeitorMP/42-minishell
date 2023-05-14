/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:45:50 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 15:52:36 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_path(char **envp)
{
	char	*key;

	while (*envp)
	{
		key = get_key_from_str(*envp);
		if (is_equal(key, "PATH"))
		{
			free(key);
			return (get_value_from_str(*envp));
		}
		free(key);
		envp++;
	}
	return (ft_strdup("-"));
}

char	*find_path(char *final, char **paths)
{
	char	*temp;
	char	*cmd;
	int		i;

	if (access(final, F_OK) == 0 && !is_equal(final, "cat"))
	{
		cmd = ft_strdup(final);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(temp, final);
		free(temp);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

int	do_command(t_root *root)
{
	char	**paths;
	char	*envp2;
	char	*cmd_path;

	cmd_path = NULL;
	dup2(root->in, 0);
	dup2(root->out, 1);
	envp2 = get_path(root->env_array);
	paths = ft_split(envp2, ':');
	if (root->tree->command[0] != NULL)
		cmd_path = find_path(root->tree->command[0], paths);
	free_array(paths);
	if (!cmd_path)
		exit (e_pro_fork(":command not found", root, 127, 1));
	if (execve(cmd_path, root->tree->command, root->env_array) < 0)
	{
		free(cmd_path);
		exit (e_pro_fork("execve error", root, 1, 1));
	}
	exit (0);
}

int	*get_doublequotes(t_root *r, char **split)
{
	int	*a_dquotes;

	a_dquotes = (int *)malloc(sizeof(int) * r->len);
	while (r->j < r->len)
	{
		if (r->i == r->j)
		{
			while (split[r->a])
			{
				a_dquotes[r->j] = r->tree->dquotes[r->b];
				r->a++;
				r->j++;
			}
			r->b++;
		}
		else
		{
			a_dquotes[r->j] = r->tree->dquotes[r->b];
			r->j++;
			r->b++;
		}
	}
	return (a_dquotes);
}

void	get_quotes2(int **squotes, int **dquotes, t_root *r, char **split)
{
	int	*a_squotes;
	int	*a_dquotes;

	start_ints(&r->a, &r->j, &r->b);
	a_squotes = get_singlequotes(r, split);
	a_dquotes = get_doublequotes(r, split);
	*squotes = a_squotes;
	*dquotes = a_dquotes;
}
