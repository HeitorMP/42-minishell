/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:51:51 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/13 09:49:11 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*nodes_split2(char **split, char s, int i, int a)
{
	t_lexer	*node;

	node = NULL;
	while (split[i])
	{
		if (!ft_strncmp(split[i], " ", 1) && ft_strlen(split[i]) == 1)
			i++;
		else
		{
			if (!node)
				node = lexical_node(split[i], s + '0', a);
			else
			{
				node->next = lexical_node(split[i], s + '0', a);
				node->next->prev = node;
				node = node->next;
			}
			a++;
			i++;
		}
	}
	while (node->prev)
		node = node->prev;
	return (node);
}

t_lexer	*nodes_split(char *test, char s, int a)
{
	t_lexer	*node;
	char	**split;
	int		i;

	i = 0;
	node = NULL;
	while (test[i] != '\0')
	{
		if (test[i] == s)
			a++;
		i++;
	}
	i = 0;
	split = ft_split(test, s);
	while (split[i])
		i++;
	if (i == 1 || !split_check(split) || a == 1)
	{
		free_str_split(split);
		return (NULL);
	}
	node = nodes_split2(split, s, 0, 0);
	free_str_split(split);
	return (node);
}

char	*first_quotes(char *str, int *b, int *j, t_lexer **node)
{
	char	*test;
	char	s;
	int		len;

	s = str[*b];
	*j = *b;
	test = NULL;
	len = get_lenlexer(str, s);
	test = ft_substr(str, (*j) + 1, len - (*j) - 1);
	if (len == (int)ft_strlen(str) - 1)
	{
		*node = nodes_split(test, s, 0);
		*j = ft_strlen(test);
		*b = len;
	}
	else
	{
		*j = 0;
		while (test[*j] != s && test[*j] != '\0')
			(*j)++;
		*b = len;
	}
	(*b)++;
	return (test);
}

char	*second_quotes(int *j, char *test, char s, char *str)
{
	int		a;
	int		c;
	char	*aux;
	char	*aux2;

	c = *j;
	(*j)++;
	a = 0;
	while (test[*j] != s && test[*j] != '\0')
	{
		if (test[*j] != ' ')
			a++;
		(*j)++;
	}
	if (a == 0)
		aux = ft_substr(test, 0, c);
	aux2 = malloc(sizeof(char) * 2);
	aux2[0] = ' ';
	aux2[1] = '\0';
	aux = ft_strjoin(aux, aux2);
	test = lexer_strjoin(aux, ft_substr(test, *j + 1, ft_strlen(str) - 1));
	free(aux2);
	return (test);
}

t_lexer	*treating_quotes(char *str, char s, int *b)
{
	t_lexer	*node;
	int		j;
	char	*test;
	char	*test1;

	node = NULL;
	test = first_quotes(str, b, &j, &node);
	if (j == (int)ft_strlen (test) || \
	!closing_q2(test, test[j], j, ft_strlen(test)) || str[*b] == ' ' \
	|| str[*b] == 39 || str[*b] == 34)
	{
		(*b)--;
		if (!node)
			node = lexical_node(test, str[*b] + '0', *b);
		free(test);
		return (node);
	}
	test1 = second_quotes(&j, test, s, str);
	free(test);
	node = treating_quotes2(s, test1);
	*b = j;
	free(test1);
	return (node);
}
