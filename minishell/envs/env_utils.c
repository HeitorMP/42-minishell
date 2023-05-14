/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:42:25 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/18 15:56:07 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envlst	*ft_lstnew_env(char *key, char *value)
{
	t_envlst	*node;

	node = malloc(sizeof(t_envlst));
	if (!node)
		return (NULL);
	node->key = (char *)key;
	node->value = (char *)value;
	node->next = NULL;
	return (node);
}

t_envlst	*ft_lstlast_envlst(t_envlst *envs)
{
	while (envs)
	{
		if (envs->next)
			envs = envs->next;
		else
			break ;
	}
	return (envs);
}

void	ft_lstadd_back_env(t_envlst **envs, t_envlst *new)
{
	t_envlst	*node;

	if (new)
	{
		if (!envs[0])
			envs[0] = new;
		else
		{
			node = ft_lstlast_envlst(*envs);
			node->next = new;
		}
	}
}

void	print_envlsts(t_root *root)
{
	t_envlst	*head;

	head = root->env_lst;
	while (root->env_lst)
	{
		if (root->env_lst->value)
		{
			ft_putstr_fd(root->env_lst->key, root->out);
			ft_putstr_fd("=", root->out);
			ft_putstr_fd(root->env_lst->value, root->out);
			ft_putchar_fd('\n', root->out);
		}
		root->env_lst = root->env_lst->next;
	}
	root->env_lst = head;
}
