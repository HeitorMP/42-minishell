/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:05:02 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/06 15:31:16 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	size_t	len;

	len = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(sizeof(char), len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	free(s1);
	return (dest);
}

static	char	*assembly_prompt(t_root *root)
{
	char	*prompt;

	prompt = NULL;
	prompt = ft_strjoin_gnl(prompt, root->user);
	prompt = ft_strjoin_gnl(prompt, "@miniteam:");
	return (prompt);
}

char	*get_prompt(t_root *root)
{
	char	*prompt;
	char	*pwd;
	char	*home;
	int		size;

	pwd = get_pwd();
	home = ft_strdup(getenv("HOME"));
	if (home == NULL)
		home = ft_strdup("/");
	size = ft_strlen(home);
	prompt = assembly_prompt(root);
	if (ft_strncmp(pwd, home, size) == 0)
	{
		prompt = ft_strjoin_gnl(prompt, "~");
		prompt = ft_strjoin_gnl(prompt, pwd + size);
	}
	else
		prompt = ft_strjoin_gnl(prompt, pwd);
	prompt = ft_strjoin_gnl(prompt, "$ ");
	free(pwd);
	free(home);
	pwd = NULL;
	home = NULL;
	return (prompt);
}
