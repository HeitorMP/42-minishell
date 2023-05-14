/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_command1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:10:00 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 13:27:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*creatingvalue3(char *cmd, int j)
{
	int		a;
	char	*temp;

	a = j;
	temp = NULL;
	while (cmd[j])
		j++;
	if (a < j)
		temp = ft_substr(cmd, a, j);
	else
		temp = ft_strdup("");
	return (temp);
}

char	*creatingvalue2(char *cmd, char **temp)
{
	char	*str;
	int		j;

	j = 0;
	str = NULL;
	if (cmd[j] == ' ' || cmd[j] == 34 || cmd[j] == 39)
	{
		*temp = ft_strdup("");
		return (cmd);
	}
	while (cmd[j] != '\0')
	{
		if (cmd[j] == ' ' || cmd[j] == 34 || cmd[j] == 39)
			break ;
		j++;
	}
	str = ft_substr(cmd, 0, j);
	*temp = creatingvalue3(cmd, j);
	free(cmd);
	return (str);
}

char	**create_split3(char **split, int *i)
{
	char	**split3;
	char	*str;

	*i = 0;
	while (split[*i])
		(*i)++;
	split3 = (char **)malloc(sizeof(char *) * (*i + 1));
	*i = 0;
	while (split[*i])
	{
		split[*i] = creatingvalue2(split[*i], &str);
		split3[*i] = ft_strdup(str);
		free(str);
		str = NULL;
		(*i)++;
	}
	split3[*i] = 0;
	return (split3);
}

char	**create_split2(char **split, char **split3, int i, int len)
{
	char	**split2;
	int		j;

	j = 0;
	split2 = ft_calloc(sizeof(char *), len + 1);
	while (i < len - 1)
	{
		split2[i] = ft_strdup("$");
		i++;
		split2[i] = ft_strdup(split[j]);
		i++;
		split2[i] = ft_strdup(split3[j]);
		j++;
		i++;
	}
	return (split2);
}

char	**creatingvalue(char **split)
{
	char	**split3;
	char	**split2;
	int		i;
	int		len;

	split3 = create_split3(split, &i);
	len = i * 2 + 1;
	if (i % 2 == 0)
		len += i;
	else
		len = len + i - 1;
	split2 = create_split2(split, split3, 0, len);
	free_str_split(split);
	free_str_split(split3);
	return (split2);
}
