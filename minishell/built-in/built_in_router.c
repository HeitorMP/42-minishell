/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_router.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:13:35 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/28 18:30:57 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	built_in_router(t_root *root)
{
	if (is_equal(root->tree->command[0], "cd"))
		return (cd(root));
	if (is_equal(root->tree->command[0], "echo"))
		return (echo(root));
	if (is_equal(root->tree->command[0], "env"))
		return (env(root));
	if (is_equal(root->tree->command[0], "export"))
		return (export(root));
	if (is_equal(root->tree->command[0], "pwd"))
		return (pwd(root));
	if (is_equal(root->tree->command[0], "exit"))
		return (ft_exit(root));
	if (is_equal(root->tree->command[0], "unset"))
		return (unset(root));
	return (FALSE);
}
