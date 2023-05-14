/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:58:59 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/10 22:28:32 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_all_num(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == '+' || cmd[i] == '-')
		i++;
	while (cmd[i])
	{
		if (!ft_isdigit(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_root *root)
{
	int	temp_exit;

	temp_exit = 0;
	if (get_array_size(root->tree->command) == 1)
		temp_exit = 0;
	else if (root->tree->command[1] && !is_all_num(root->tree->command[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", \
			STDERR);
		temp_exit = 2;
	}
	else if (get_array_size(root->tree->command) > 2)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", STDERR);
		return (1);
	}
	else
		temp_exit = ft_atoi(root->tree->command[1]);
	free_all(root, 0);
	exit(temp_exit);
}
