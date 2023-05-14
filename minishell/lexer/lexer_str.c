/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:03:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 10:27:22 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_string3(char *line, int *i, int len)
{
	char	*aux;
	char	*str;
	char	*str2;
	char	s;

	aux = NULL;
	str2 = create_string4(line, i, len, &s);
	if (*i == len)
		return (str2);
	str = ft_strdup(str2);
	free(str2);
	str2 = mid_str(line, i, str, len);
	if (!str2)
		str2 = ft_strdup(str);
	free(str);
	if (*i == len)
		return (str2);
	s = line[*i];
	aux = aux_quotes(line, i, len, s);
	str = ft_strdup(str2);
	free(str2);
	str2 = complete_strlexer(str, aux);
	free(aux);
	free(str);
	return (str2);
}

char	*treat_end(char *line, int len, int i)
{
	int		a;
	char	*str;

	a = i;
	str = NULL;
	while (line[i] == 34 || line[i] == 39)
		i++;
	if (i == len && i > a)
		str = ft_strdup(&line[a]);
	return (str);
}

char	*treat_begin(char *line, int len)
{
	int		i;
	int		len1;
	char	*str;

	i = 0;
	len1 = len - 1;
	while (line[i] == 34 || line[i] == 39)
		i++;
	while (line[len1] != 34 && line[len1] != 39)
		len1--;
	if (len1 + 1 == i)
	{
		str = ft_substr(line, i, len);
		return (str);
	}
	return (NULL);
}

char	*create_string2(char *line, int len)
{
	int		i;
	char	*str1;
	char	*aux;

	i = 0;
	aux = NULL;
	str1 = NULL;
	while (line[i] != 34 && line[i] != 39 && i < len)
		i++;
	if (i == len)
	{
		str1 = ft_strdup(line);
		return (str1);
	}
	if (i > 0)
		aux = ft_substr(line, 0, i);
	str1 = final_aux(line, aux, len, &i);
	if (aux)
		free(aux);
	return (str1);
}

char	*create_string(char *line)
{
	int		len;
	int		a;
	int		i;
	char	*str;

	if (line[0] == '\0')
		return (NULL);
	len = ft_strlen(line);
	a = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34 || line[i] == 39)
			a++;
		i++;
	}
	if (a == len)
	{
		write(2, "syntax error\n", 13);
		return (NULL);
	}
	str = create_string2(line, len);
	return (str);
}
