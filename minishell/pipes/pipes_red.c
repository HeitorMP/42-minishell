/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:20:08 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/06 20:19:03 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_input(t_root *root, int i, int max)
{
	int	in;

	if (i == 0)
		in = 0;
	else if (i == max - 1)
		in = root->pipes[root->num_pipes * 2 - 2];
	else
		in = root->pipes[2 * i - 2];
	if (root->isbuilt != 0)
	{
		close(root->isbuilt);
		in = open(".temp", O_RDONLY);
		root->isbuilt = 0;
	}
	return (in);
}

int	get_output(t_root *root, int i, int max)
{
	int	out;

	if (i == 0)
		out = root->pipes[1];
	else if (i == max -1)
		out = 1;
	else
		out = root->pipes[2 * i + 1];
	return (out);
}

int	checking_redirects_pipes(t_root *root, int i, int max)
{
	if (checking_redirects(root, &(root->status)))
	{
		root->tree = root->tree->rigth;
		return (root->status);
	}
	if (root->in == 0)
		root->in = get_input(root, i, max);
	if (root->out == 1)
		root->out = get_output(root, i, max);
	return (0);
}

void	deleting_tempfiles(t_ast *t)
{
	while (t->prev)
		t = t->prev;
	while (t)
	{
		if (t->type == here_doc)
			unlink(".here_doc");
		if (t->type == command && is_built(t->command, 0))
			unlink(".temp");
		else if (t->left && t->left->type == command && \
		is_built(t->left->command, 0))
			unlink(".temp");
		if (!t->rigth)
			break ;
		t = t->rigth;
	}
}
