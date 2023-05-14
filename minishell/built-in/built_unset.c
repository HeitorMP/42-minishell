/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:16:13 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/04 14:57:43 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset(t_root *root)
{
	t_envlst	*head;
	t_envlst	*to_delete;
	int			cmd;

	cmd = 1;
	head = root->env_lst;
	while (root->tree->command[cmd])
	{
		while (root->env_lst && root->env_lst->next)
		{
			if (is_equal(root->tree->command[cmd], root->env_lst->next->key))
			{
				to_delete = root->env_lst->next;
				root->env_lst->next = root->env_lst->next->next;
				free_env_node(to_delete);
			}
			root->env_lst = root->env_lst->next;
		}
		root->env_lst = head;
		cmd++;
	}
	refresh_env_array(root);
	return (0);
}
