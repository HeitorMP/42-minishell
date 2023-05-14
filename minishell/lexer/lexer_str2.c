/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:42 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 13:16:15 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_string2(char *line, int *i, int *len1)
{
	int	b;

	b = 1;
	while (line[*len1] == line[*len1 - 1] && line[*i] == line[*i + 1])
	{
		(*len1)--;
		(*i)++;
		b++;
	}
	if (b % 2 == 0)
	{
		(*i)++;
		(*len1)--;
	}
}

char	*find_string(char *line, int *i, int len)
{
	char	s;
	int		len1;
	int		test;
	char	*aux;

	s = line[*i];
	len1 = len - 1;
	while (line[len1] != s)
		len1--;
	test = len1;
	find_string2(line, i, &len1);
	if (len1 >= *i)
		aux = ft_substr(line, *i, len1 - *i + 1);
	else
		aux = ft_strdup("");
	*i = test + 1;
	return (aux);
}

char	*auxquotes2(char *line, int *i, int len, char s)
{
	int		c;
	char	*aux;
	char	*aux1;

	aux = find_string(line, i, len);
	aux1 = NULL;
	if (aux && aux[0] == s && aux[ft_strlen(aux) - 1] == s)
	{
		c = 1;
		aux1 = create_string3(aux, &c, ft_strlen(aux) - 1);
		if (aux1)
			aux1 = add_quotes(s, aux1);
	}
	else if (aux)
	{
		c = 0;
		aux1 = create_string3(aux, &c, ft_strlen(aux));
	}
	free(aux);
	return (aux1);
}

char	*aux_quotes(char *line, int *i, int len, char s)
{
	char	*aux;
	int		a;

	aux = NULL;
	if (closing_q2(line, line[*i], *i, len))
		aux = auxquotes2(line, i, len, s);
	else
	{
		a = *i;
		(*i)++;
		while (line[*i] != 34 && line[*i] != 39 && *i < len)
			(*i)++;
		aux = ft_substr(line, a, *i - a);
	}
	return (aux);
}

char	*add_quotes(char s, char *aux)
{
	char	*str;
	char	*aux2;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = s;
	str[1] = '\0';
	aux2 = NULL;
	aux2 = ft_strdup(aux);
	free(aux);
	aux = NULL;
	aux = ft_strjoin(str, aux2);
	free(aux2);
	aux2 = NULL;
	aux2 = ft_strdup(aux);
	free(aux);
	aux = NULL;
	aux = ft_strjoin(aux2, str);
	free(str);
	free(aux2);
	return (aux);
}
