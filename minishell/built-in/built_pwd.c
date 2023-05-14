/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:39:44 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/07 21:12:12 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd(t_root *root)
{
	char	*pwd;

	pwd = get_pwd();
	if (pwd)
	{
		ft_putstr_fd(pwd, root->out);
		ft_putchar_fd('\n', root->out);
		free(pwd);
	}
	return (0);
}
