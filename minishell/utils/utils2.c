/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:26:24 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/04 13:28:56 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_test3(char **s, int j, char *aux)
{
	char	*aux2;
	char	*temp;

	temp = NULL;
	if (ft_strlen(s[j]) == 1)
		temp = ft_strdup(aux);
	else if (ft_strlen(s[j]) > 1)
	{
		aux2 = ft_substr(s[j], 1, ft_strlen(s[j]) - 1);
		temp = ft_strjoin(aux, aux2);
		free(aux2);
	}
	return (temp);
}
