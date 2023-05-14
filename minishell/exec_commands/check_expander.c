/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:34:29 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/10 18:29:26 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	loop_aux_file(int *a, int *i, t_root *r)
{
	while (r->tree->file[*i] != '\0')
	{
		if (r->tree->file[*i] == '$')
		{
			*a = *i;
			(*i)++;
			while (r->tree->file[*i] != '\0' && \
			r->tree->file[*i] != '$' && r->tree->file[*i] != ' ')
				(*i)++;
			break ;
		}
		(*i)++;
	}
}

void	find_auxs(char **aux, char **aux2, t_root *r, int *a)
{
	int		i;
	char	*n;

	i = 0;
	*a = 0;
	*aux = NULL;
	*aux2 = NULL;
	n = ft_itoa(r->status_old);
	loop_aux_file(a, &i, r);
	if (r->tree->file[*a + 1] == '?')
		*aux = ft_strdup(n);
	else
		*aux = ft_substr(r->tree->file, *a, i);
	if (i > 0)
		*aux2 = ft_substr(r->tree->file, 0, *a);
	free(n);
}

char	*new_file(char *value, char *aux2)
{
	char	*new;

	new = NULL;
	if (aux2 && value)
		new = ft_strjoin(aux2, value);
	else if (!aux2 && value)
		new = ft_strdup(value);
	else if (!value && aux2)
		new = ft_strdup(aux2);
	return (new);
}

int	file_expander(t_root *r)
{
	char	*value;
	char	*aux;
	char	*aux2;
	int		a;

	find_auxs(&aux, &aux2, r, &a);
	if (r->tree->file[a + 1] != '?')
		value = get_env_value(r, aux + 1);
	else
		value = ft_strdup(aux);
	if (!value && aux2[0] == '\0' && r->tree->file[a + 1] != '?')
	{
		free(aux);
		if (aux2)
			free(aux2);
		return (e_pro(": ambiguous redirect", r->tree, 1, 0));
	}
	free(r->tree->file);
	r->tree->file = NULL;
	r->tree->file = new_file(value, aux2);
	free(value);
	free(aux);
	if (aux2)
		free(aux2);
	return (0);
}

int	check_expander(t_root *r)
{
	if (r->tree->type == file)
	{
		if (r->tree->prev->type != here_doc && check_dollar(r->tree->file) \
			&& r->tree->squotes[0] == -1)
			r->status = file_expander(r);
	}
	else if (r->tree->type == command && r->tree->command && \
		!is_equal(r->tree->command[0], "export") && \
		!is_equal(r->tree->command[0], "unset"))
		command_expander(r);
	if (r->tree->left)
	{
		r->tree = r->tree->left;
		check_expander(r);
	}
	if (r->tree->rigth)
	{
		r->tree = r->tree->rigth;
		check_expander(r);
	}
	if (r->status)
		return (r->status);
	return (0);
}
