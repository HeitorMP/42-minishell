/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:25:58 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/10 22:10:28 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_valid_option(char *op)
{
	int	i;

	i = 2;
	if (op && ft_strncmp(op, "-n", 2) == 0)
	{
		while (op[i])
		{
			if (op[i] != 'n')
				break ;
			i++;
		}
		return (1);
	}
	return (0);
}

static int	do_print_echo(t_root *root, char *cmd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(cmd))
	{
		ft_putchar_fd(cmd[i], root->out);
		i++;
	}
	return (1);
}

static int	loop_echo(t_root *root)
{
	int	cmd;

	cmd = 1;
	while (is_valid_option(root->tree->command[cmd]) && \
		root->tree->command[cmd])
			cmd++;
	while (root->tree->command[cmd])
	{
		do_print_echo(root, root->tree->command[cmd]);
		cmd++;
		if (root->tree->command[cmd])
			ft_putchar_fd(' ', root->out);
	}
	if (!is_valid_option(root->tree->command[1]))
		ft_putchar_fd('\n', root->out);
	return (0);
}

int	echo(t_root *root)
{
	if (get_array_size(root->tree->command) <= 1)
		ft_putchar_fd('\n', root->out);
	else
		loop_echo(root);
	return (0);
}
