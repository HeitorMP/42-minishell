/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:58:38 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/14 09:55:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*first_node(char *main, int *i, char **test)
{
	t_lexer	*node;
	int		start;
	int		len;

	start = *i;
	if (endofquotes(main[*i]))
		(*i)++;
	while (!endofstring(main[*i]))
		(*i)++;
	len = *i - start;
	*test = ft_substr(main, start, len);
	node = lexical_node(*test, 0, start);
	return (node);
}

int	check_firstnode(char *main, int *i, t_lexer **node)
{
	char	*test;
	int		a;

	a = 0;
	*node = NULL;
	test = NULL;
	while (main[*i] == ' ')
		(*i)++;
	if (check_signal1(main, i, node))
		return (2);
	if (*node != NULL)
		return (0);
	if (endofquotes(main[*i]) && closing_q(main, main[*i], *i, &a))
	{
		*node = treating_quotes(main, main[*i], i);
		(*i)++;
	}
	else
		*node = first_node(main, i, &test);
	free(test);
	return (0);
}

void	add_index(t_lexer **node, char **str)
{
	int	i;

	while ((*node)->prev)
		*node = (*node)->prev;
	i = 0;
	while (*node)
	{
		(*node)->number = i;
		if (!(*node)->next)
			break ;
		*node = (*node)->next;
		i++;
	}
	while ((*node)->prev)
		*node = (*node)->prev;
	free(*str);
	*str = NULL;
}

int	start_lexer(char **str, char *line, int *i, t_lexer **node, t_root *r)
{
	*i = 0;
	*str = create_string(line);
	if (*str == NULL)
	{
		r->status = 1;
		return (1);
	}
	if (check_firstnode(*str, i, node))
	{
		free(*str);
		*str = NULL;
		r->status = 2;
		return (2);
	}
	return (0);
}

int	lexical_annalysis(t_lexer **node, char *line, t_root *r)
{
	int		i;
	int		j;
	char	*str;

	if (start_lexer(&str, line, &i, node, r))
	{
		r->status = 2;
		return (2);
	}
	while (str[i] != '\0')
	{
		j = i;
		if (check_signal3(&str, &i, node))
		{
			r->status = 2;
			return (2);
		}
		if (!(*node)->next && str[i] != ' ')
			(*node)->next = node_str(str, &i, j);
		if ((*node)->next)
		{
			(*node)->next->prev = *node;
			*node = (*node)->next;
			while ((*node)->next)
				(*node) = (*node)->next;
		}
		i++;
	}
	add_index(node, &str);
	return (0);
}
