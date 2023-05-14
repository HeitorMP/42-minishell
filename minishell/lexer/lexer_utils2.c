/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:59:00 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 09:55:25 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_signal1(char *main, int *i, t_lexer **node)
{
	if (main[*i] == '|')
		return (error_syntax(&main[*i], 2));
	*node = sign_node(i, main[*i], main);
	if (*node != NULL)
		(*i)++;
	return (0);
}

int	check_signal(char *main, int *i, t_lexer **node)
{
	if (main[*i] == ' ' || main[*i] == '\0')
		return (0);
	if (endofstring(main[*i]) && !node_type(*node, main[*i]))
		(*node)->next = sign_node(i, main[*i], main);
	else if (endofstring(main[*i]) && node_type(*node, main[*i]))
		return (error_syntax(&main[*i], 2));
	return (0);
}

t_lexer	*sign_node(int *i, char s, char *str)
{
	t_lexer	*node;

	node = NULL;
	if (str[*i] == str[*i + 1] && (str[*i] == '<' || str[*i] == '>'))
	{
		if (s == '<')
			node = lexical_node(NULL, here_doc, *i);
		else
			node = lexical_node(NULL, app_out, *i);
		(*i)++;
		return (node);
	}
	if (s == '|')
		node = lexical_node(NULL, pipem, *i);
	else if (s == '<')
		node = lexical_node(NULL, red_in, *i);
	else if (s == '>')
		node = lexical_node(NULL, red_out, *i);
	return (node);
}

int	closing_q2(char *str, char c, int i, int len)
{
	i++;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*lexer_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
		return (NULL);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, len1 + 1);
	ft_strlcat(str, (char *)s2, len2 + len1 + 1);
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}
