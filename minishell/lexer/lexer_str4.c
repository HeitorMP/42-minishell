/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:08 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 10:27:35 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_string4(char *line, int *i, int len, char *s)
{
	char	*aux;
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;
	aux = NULL;
	str = start_str(line, i, len);
	if (*i == len)
		return (str);
	*s = line[*i];
	aux = aux_quotes(line, i, len, *s);
	str2 = complete_strlexer(str, aux);
	if (str)
		free(str);
	free(aux);
	*s = change_q(*s);
	return (str2);
}

char	*final_aux(char *line, char *aux, int len, int *i)
{
	char	*str;
	char	*str1;

	str = NULL;
	str1 = NULL;
	str = treat_begin(line, len);
	str = treat_end(line, len, *i);
	if (!str)
		str = create_string3(line, i, len);
	if (aux && str)
		str1 = ft_strjoin(aux, str);
	else if (!aux && str)
		str1 = ft_strdup(str);
	else if (aux && !str)
		str1 = ft_strdup(aux);
	if (str)
		free(str);
	return (str1);
}

int	get_lenlexer(char *str, char s)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (str[len] != s)
		len--;
	return (len);
}

t_lexer	*treating_quotes2(char s, char *test)
{
	char	**split;
	t_lexer	*node;

	split = ft_split(test, ' ');
	node = nodes_split2(split, s, 0, 0);
	free_str_split(split);
	return (node);
}

int	check_signal3(char **str, int *i, t_lexer **node)
{
	if (check_signal(*str, i, node))
	{
		free(*str);
		*str = NULL;
		return (2);
	}
	return (0);
}
