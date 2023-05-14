/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:36:48 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/24 20:13:16 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_equal(char *command, char *key)
{
	if (command == NULL)
		return (FALSE);
	if (ft_strncmp(command, key, ft_strlen(key)) == 0 && \
		ft_strlen(command) == ft_strlen(key))
		return (TRUE);
	return (FALSE);
}

char	*transform(char cwd[])
{
	char	*path;
	int		i;

	i = 0;
	path = ft_calloc(sizeof(char), ft_strlen(cwd) + 1);
	while (cwd[i])
	{
		path[i] = cwd[i];
		i++;
	}
	return (path);
}

char	*get_pwd(void)
{
	char	cwd[BUFFER_PATH];

	getcwd(cwd, BUFFER_PATH);
	return (transform(cwd));
}

int	is_built(char **commands, int i)
{
	if (commands == NULL)
		return (FALSE);
	if (commands[0] == NULL)
		return (FALSE);
	if (is_equal(commands[0], "cd") && i != 1)
		return (TRUE);
	if (is_equal(commands[0], "echo"))
		return (TRUE);
	if (is_equal(commands[0], "env"))
		return (TRUE);
	if (is_equal(commands[0], "export"))
		return (TRUE);
	if (is_equal(commands[0], "pwd"))
		return (TRUE);
	if (is_equal(commands[0], "exit") && i != 1)
		return (TRUE);
	if (is_equal(commands[0], "unset"))
		return (TRUE);
	return (FALSE);
}
