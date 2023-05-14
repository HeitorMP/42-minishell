/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:20:32 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/18 16:30:26 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_envp_lst(t_root *root)
{
	t_envlst	*temp;

	while (root->env_lst)
	{
		temp = root->env_lst;
		root->env_lst = root->env_lst->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

void	free_env_node(t_envlst *node)
{
	free(node->key);
	free(node->value);
	free(node);
}
