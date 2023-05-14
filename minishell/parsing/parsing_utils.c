/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:04:40 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/14 10:19:43 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_file(t_lexer **lexer, t_ast *node)
{
	while (*lexer)
	{
		if ((*lexer)->number == node->node + 1)
			return (0);
		*lexer = (*lexer)->next;
	}
	return (error_syntax("'newline'", 2));
}

int	pipes_lexer(t_lexer *lexer)
{
	int	p;

	p = 0;
	while (lexer->prev)
		lexer = lexer->prev;
	while (lexer)
	{
		if (lexer->type == pipem)
			p++;
		if (!lexer->next)
			break ;
		lexer = lexer->next;
	}
	return (p);
}

int	length_lexer(t_lexer *lexer, t_ast *aux, int i)
{
	int	len;

	len = 0;
	if (i == 0)
	{
		while (lexer->next)
		{
			len++;
			lexer = lexer->next;
		}
		len++;
	}
	else
		len = checking_nodes(aux, lexer, i);
	return (len);
}

char	**newstring(t_lexer **lexer, t_ast **tree)
{
	char	**new;
	int		len;

	len = length_lexer(*lexer, NULL, 0);
	new = create_array(lexer, len, tree);
	return (new);
}

char	**treat_string(t_lexer **lexer, t_ast **aux, t_ast **tree)
{
	char	**new;
	int		len;

	new = NULL;
	if (aux == NULL)
		new = newstring(lexer, tree);
	else
	{
		if (!pipes_lexer(*lexer))
			len = length_lexer(*lexer, *aux, 1);
		else
		{
			if ((*aux)->left == NULL)
				len = length_lexer(*lexer, *aux, 2);
			else
				len = length_lexer(*lexer, *aux, 3);
		}
		new = create_array(lexer, len, tree);
		if (is_file((*lexer)->type))
			passing_file(lexer);
		if ((*lexer)->next != NULL)
			*lexer = (*lexer)->next;
	}
	return (new);
}

void	print_tree(t_ast *node, int i)
{
	int	j;
	int	a;

	j = i;
	a = 0;
	while (j > 0)
	{
		printf("\t");
		j--;
	}
	j = 0;
	if (node->command)
	{
		printf("node_check: %d, ", node->type);
		printf("node->command:");
		while (node->command[a])
		{
			printf(" %s;", node->command[a]);
			printf("dquotes %d, ", node->dquotes[a]);
			printf("squotes %d, ", node->squotes[a]);
			a++;
		}
		printf("\n");
	}
	else if (node->file)
	{
		printf("node file: %s\n", node->file);
	}
	else
		printf("node_check: %d\n", node->type);
	i++;
	if (node->left)
	{
		while (i > j)
		{
			printf("\t");
			j++;
		}
		j = 0;
		printf("left node\n");
		print_tree(node->left, i);
	}
	if (node->rigth)
	{
		while (i > j)
		{
			printf("\t");
			j++;
		}
		j = 0;
		printf("rigth node\n");
		print_tree(node->rigth, i);
	}
}
