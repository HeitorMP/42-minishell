/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:28:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/04/26 11:30:39 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*create_nodeaux(t_ast **tree, int check)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (node)
	{
		node->type = check;
		node->command = NULL;
		node->file = NULL;
		node->dquotes = NULL;
		node->squotes = NULL;
		node->left = NULL;
		node->rigth = NULL;
		if (tree)
			node->prev = *tree;
		else
			node->prev = NULL;
	}
	return (node);
}
