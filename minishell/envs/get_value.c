/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:35:27 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/04 13:27:41 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	refresh_env_array(t_root *root)
{
	t_envlst	*head;
	int			size;
	int			i;

	i = 0;
	size = get_lst_size(root->env_lst);
	free_array(root->env_array);
	root->env_array = malloc(sizeof(char *) * (size + 1));
	root->env_array[size] = 0;
	head = root->env_lst;
	while (root->env_lst)
	{
		root->env_array[i] = NULL;
		root->env_array[i] = ft_strjoin_gnl(root->env_array[i], \
							root->env_lst->key);
		if (root->env_lst->value)
		{
			root->env_array[i] = ft_strjoin_gnl(root->env_array[i], "=");
			root->env_array[i] = ft_strjoin_gnl(root->env_array[i], \
								root->env_lst->value);
		}
		i++;
		root->env_lst = root->env_lst->next;
	}
	root->env_lst = head;
}

char	*get_env_value(t_root *root, char *key)
{
	t_envlst	*head;
	char		*ret;

	head = root->env_lst;
	ret = NULL;
	while (root->env_lst)
	{
		if (is_equal(key, root->env_lst->key))
		{
			ret = ft_strdup(root->env_lst->value);
			break ;
		}
		root->env_lst = root->env_lst->next;
	}
	root->env_lst = head;
	return (ret);
}

int	print_env_value(t_root *root, char *key)
{
	t_envlst	*head;

	head = root->env_lst;
	while (root->env_lst)
	{
		if (is_equal(key, root->env_lst->key))
		{
			printf("%s", root->env_lst->value);
			root->env_lst = head;
			return (TRUE);
		}
		root->env_lst = root->env_lst->next;
	}
	root->env_lst = head;
	return (FALSE);
}

int	change_value(t_root *root, char *key, char *new_value)
{
	t_envlst	*head;

	head = root->env_lst;
	while (root->env_lst)
	{
		if (is_equal(key, root->env_lst->key))
		{
			free(root->env_lst->value);
			free(root->env_lst->key);
			root->env_lst->value = ft_strdup(new_value);
			root->env_lst->key = ft_strdup(key);
			root->env_lst = head;
			return (1);
		}
		root->env_lst = root->env_lst->next;
	}
	root->env_lst = head;
	refresh_env_array(root);
	return (0);
}
