/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_commands2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:28:46 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 12:36:30 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_ints(int *a, int *j, int *b)
{
	*j = 0;
	*a = 0;
	*b = 0;
}

char	**final_str2(t_root *r, int i, char **split, char **final)
{
	start_ints(&r->a, &r->j, &r->b);
	while (r->j < r->len)
	{
		if (i == r->j)
		{
			while (split[r->a])
			{
				final[r->j] = ft_strdup(split[r->a]);
				r->a++;
				r->j++;
			}
			r->b++;
		}
		else
		{
			final[r->j] = ft_strdup(r->tree->command[r->b]);
			r->b++;
			r->j++;
		}
	}
	return (final);
}

char	**final_str(char **split, t_root *r, int i)
{
	char	**final;

	final = (char **)malloc(sizeof(char *) * (r->len + 1));
	final = final_str2(r, i, split, final);
	return (final);
}

char	**complete_command(char **final, int len)
{
	char	**str;
	int		j;

	str = NULL;
	str = (char **)malloc(sizeof(char *) * (len + 1));
	j = 0;
	while (j < len)
	{
		str[j] = ft_strdup(final[j]);
		j++;
	}
	str[j] = 0;
	return (str);
}

void	command_expander2(char *value, int *i, t_root *r)
{
	char	**split;
	char	**final;

	r->j = 0;
	split = NULL;
	final = NULL;
	split = ft_split(value, ' ');
	while (split[r->j])
		r->j++;
	r->len = r->j;
	r->j = 0;
	while (r->tree->command[r->j])
		r->j++;
	r->len = r->len + r->j - 1;
	final = final_str(split, r, *i);
	final[r->len] = 0;
	r->i = *i;
	get_quotes(r, split);
	free_str_split(r->tree->command);
	r->tree->command = NULL;
	r->tree->command = complete_command(final, r->len);
	free_str_split(split);
	free_str_split(final);
	*i = 0;
}
