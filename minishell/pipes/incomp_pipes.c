/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incomp_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:34:38 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/14 12:14:29 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*complete_str(void)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		write(1, ">", 1);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		str = get_next_line(0);
		if (!str)
			return (NULL);
		while (str[i] == ' ')
			i++;
		if (str[i] != '\n')
			return (str);
		free(str);
	}
	return (NULL);
}

char	*create_completepipe(t_ast *tree, int *i, char *str)
{
	char	*new;

	new = NULL;
	*i = 0;
	while (1)
	{
		if (tree->type == pipem)
		{
			if (!tree->rigth)
			{
				str = complete_str();
				*i = 1;
				if (!str)
					return (NULL);
				break ;
			}
		}
		if (!tree->rigth)
			return (NULL);
		tree = tree->rigth;
	}
	new = ft_substr(str, 0, ft_strlen(str) - 1);
	free(str);
	return (new);
}

void	checking_unfinishpipes(t_root *r)
{
	char	*new;
	t_lexer	*node;
	t_ast	*aux;
	int		i;

	aux = NULL;
	new = NULL;
	new = create_completepipe(r->tree, &i, NULL);
	if (!new && i == 1)
	{
		free_tree(&r->tree, 0);
		r->tree = NULL;
	}
	else if (new)
	{
		lexical_annalysis(&node, new, r);
		parsing_str(&node, &aux, r);
		while (r->tree->rigth)
			r->tree = r->tree->rigth;
		r->tree->rigth = aux;
		aux->prev = r->tree;
		while (r->tree->prev)
			r->tree = r->tree->prev;
		free(new);
		checking_unfinishpipes(r);
	}
}
