/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:55:23 by idias-al          #+#    #+#             */
/*   Updated: 2023/04/06 13:18:29 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*test;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	test = (char *)malloc(sizeof(char) * (len + 1));
	if (!test)
		return (NULL);
	ft_strlcpy(test, s, len + 1);
	return (test);
}
