/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:38:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/06 20:18:31 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc_loop(t_root *r)
{
	char	*buf;

	buf = NULL;
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		write(1, ">", 1);
		buf = get_next_line(0);
		if (buf == NULL)
			break ;
		if (ft_strlen(buf) == (ft_strlen(r->tree->left->file) + 1) && \
		!ft_strncmp(buf, r->tree->left->file, ft_strlen(r->tree->left->file)))
			break ;
		write(r->in, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
}

int	input_file(t_root *r)
{
	if (r->tree->type == red_in)
		r->in = open(r->tree->left->file, O_RDONLY);
	else
		r->in = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (r->in < 0)
		return (e_pro(": no such file or directory", r->tree->left, 1, 0));
	if (r->tree->type == here_doc)
	{
		here_doc_loop(r);
		r->in = open(".here_doc", O_RDONLY);
		if (r->in < 0)
			return (e_pro(": no such file or directory", r->tree->left, 1, 0));
	}
	return (0);
}

int	output_file(t_root *r)
{
	if (r->tree->type == red_out)
		r->out = open(r->tree->left->file, O_CREAT | O_TRUNC | O_RDWR, 0000666);
	else
		r->out = \
		open(r->tree->left->file, O_APPEND | O_CREAT | O_RDWR, 0000666);
	if (r->out < 0)
		return (e_pro(": no such file or directory", r->tree->left, 1, 0));
	return (0);
}

int	checking_redirects(t_root *root, int *status)
{
	while (root->tree)
	{
		if (root->tree->type == red_in || root->tree->type == here_doc)
			*status = input_file(root);
		else if (root->tree->type == red_out || root->tree->type == app_out)
			*status = output_file(root);
		else if (root->tree->type == pipem || root->tree->type == command)
			break ;
		if (!root->tree->rigth)
			break ;
		if (*status != 0)
			return (*status);
		root->tree = root->tree->rigth;
	}
	return (0);
}
