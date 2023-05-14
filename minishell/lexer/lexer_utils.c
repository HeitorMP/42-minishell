/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:54:40 by idias-al          #+#    #+#             */
/*   Updated: 2023/04/26 17:56:38 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*lexical_node(char *str, int type, int j)
{
	t_lexer	*node;

	node = malloc(sizeof(t_lexer));
	if (node)
	{
		if (str)
			node->str = ft_strdup(str);
		else
			node->str = NULL;
		node->type = type;
		node->number = j;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

int	closing_q(char *str, char c, int i, int *a)
{
	(void)a;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	endofstring(char s)
{
	if (s == '\0')
		return (1);
	else if (s == ' ')
		return (1);
	else if (s == '|')
		return (1);
	else if (s == '<')
		return (1);
	else if (s == '>')
		return (1);
	return (0);
}

int	endofquotes(char s)
{
	if (s == 34)
		return (1);
	else if (s == 39)
		return (1);
	return (0);
}

int	node_type(t_lexer *node, char s)
{
	if (node->type == red_in)
		return (1);
	else if (node->type == red_out)
		return (1);
	else if (node->type == here_doc)
		return (1);
	else if (node->type == app_out)
		return (1);
	if (s == '|')
		if (node->type == pipem)
			return (1);
	return (0);
}
