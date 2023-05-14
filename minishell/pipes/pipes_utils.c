/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:33:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 10:37:19 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	counting_pipes(t_ast *tree)
{
	int	pipes;

	pipes = 0;
	while (tree)
	{
		if (tree->type == pipem)
			pipes++;
		if (!tree->rigth)
			break ;
		tree = tree->rigth;
	}
	while (tree->prev)
		tree = tree->prev;
	return (pipes);
}

int	creating_pipes(t_root *r, int pipes)
{
	int	i;

	r->pipes = (int *)malloc(sizeof(int) * 2 * pipes);
	if (!r->pipes)
		return (1);
	i = 0;
	while (i < pipes)
	{
		if (pipe(r->pipes + (2 * i)) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	child_in(t_root *root)
{
	char	*envp2;
	char	**paths;
	char	*cmd_path;

	dup2(root->in, 0);
	dup2(root->out, 1);
	close_fd(root->tree, root->pipes);
	envp2 = get_path(root->env_array);
	paths = ft_split(envp2, ':');
	cmd_path = find_path(root->tree->command[0], paths);
	free_array(paths);
	if (!cmd_path)
		exit (e_pro_fork(" command not found", root, 127, 1));
	if (execve(cmd_path, root->tree->command, root->env_array) < 0)
	{
		free(cmd_path);
		exit (e_pro_fork("execve error", NULL, 1, 1));
	}
	exit (0);
}

int	child_out(t_root *root)
{
	char	*envp2;
	char	**paths;
	char	*cmd_path;

	dup2(root->in, 0);
	dup2(root->out, 1);
	close_fd(root->tree, root->pipes);
	envp2 = get_path(root->env_array);
	paths = ft_split(envp2, ':');
	cmd_path = find_path(root->tree->command[0], paths);
	free_array(paths);
	if (!cmd_path)
		exit (e_pro_fork(" command not found", root, 127, 1));
	if (execve(cmd_path, root->tree->command, root->env_array) < 0)
	{
		free(cmd_path);
		exit (e_pro_fork("execve error", NULL, 1, 1));
	}
	exit (0);
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
