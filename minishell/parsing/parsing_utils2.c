/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:04:40 by idias-al          #+#    #+#             */
/*   Updated: 2023/04/24 17:44:36 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_nodespart2(t_ast *tree, t_lexer *lexer, int red)
{
	int	max;
	int	start;

	start = lexer->number;
	while (tree->type != pipem)
		tree = tree->rigth;
	while (lexer->number != tree->node)
	{
		if (is_file(lexer->type))
			red += 2;
		lexer = lexer->next;
	}
	max = tree->node - red - start;
	return (max);
}

int	checking_nodes(t_ast *tree, t_lexer *lexer, int i)
{
	int	max;
	int	red;

	max = 0;
	red = 0;
	if (i == 1 || i == 3)
	{
		while (lexer->next)
		{
			max++;
			if (is_file(lexer->type))
				red += 2;
			lexer = lexer->next;
		}
		max++;
		max = max - red;
	}
	else if (i == 2)
		max = check_nodespart2(tree, lexer, red);
	return (max);
}

int	is_file(int i)
{
	if (i == red_in)
		return (1);
	else if (i == red_out)
		return (1);
	else if (i == app_out)
		return (1);
	else if (i == here_doc)
		return (1);
	return (0);
}

void	array_quotes(t_ast **tree, t_lexer **lexer, int j)
{
	if ((*lexer)->type == 82)
	{
		(*tree)->dquotes[j] = j;
		(*tree)->squotes[j] = -1;
	}
	else if ((*lexer)->type == 87)
	{
		(*tree)->squotes[j] = j;
		(*tree)->dquotes[j] = -1;
	}
	else
	{
		(*tree)->squotes[j] = -1;
		(*tree)->dquotes[j] = -1;
	}
}

char	**create_array(t_lexer **lexer, int len, t_ast **tree)
{
	int		j;
	char	**new;

	j = 0;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	(*tree)->dquotes = (int *)malloc(sizeof(int) * len);
	(*tree)->squotes = (int *)malloc(sizeof(int) * len);
	while (j < len)
	{
		if (is_file((*lexer)->type))
			passing_file(lexer);
		new[j] = ft_strdup((*lexer)->str);
		array_quotes(tree, lexer, j);
		if ((*lexer)->next == NULL || j == len - 1)
		{
			j++;
			if (j == len)
				break ;
			break ;
		}
		(*lexer) = (*lexer)->next;
		j++;
	}
	new[j] = 0;
	return (new);
}
