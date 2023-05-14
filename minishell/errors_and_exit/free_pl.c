/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:20:35 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 19:15:13 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_tree(t_ast **t, int a)
{
	while ((*t)->prev != NULL && a == 0)
		*t = (*t)->prev;
	if ((*t)->type == command && (*t)->command)
		free_str_split((*t)->command);
	else if ((*t)->type == file && (*t)->file != NULL)
		free((*t)->file);
	if ((*t)->dquotes != NULL)
		free((*t)->dquotes);
	if ((*t)->squotes != NULL)
		free((*t)->squotes);
	if ((*t)->prev != NULL)
		(*t)->prev = NULL;
	if ((*t)->rigth)
		free_tree(&((*t)->rigth), 1);
	if ((*t)->left)
		free_tree(&((*t)->left), 1);
	(*t)->rigth = NULL;
	(*t)->left = NULL;
	free((*t));
	(*t) = NULL;
}

t_lexer	*free_lexer(t_lexer *lexer)
{
	t_lexer	*to_delete;

	while (lexer->prev)
	{
		lexer = lexer->prev;
	}
	while (lexer)
	{
		to_delete = lexer;
		lexer = lexer->next;
		free(to_delete->str);
		free(to_delete);
	}
	return (NULL);
}

	/* if (lexer->next != NULL)
	{
		while (lexer)
		{
			if (lexer->prev)
				lexer->prev = NULL;
			if (lexer->str)
			{
				free(lexer->str);
				lexer->str = NULL;
			}
			if (!lexer->next)
				break ;
			lexer = lexer->next;
			free(lexer->prev);
		}
		if (lexer->prev)
			lexer->prev = NULL;
		free (lexer);
	}
	else
		free(lexer);
	lexer = NULL;
	return (lexer); */

void	mini_free(t_root *root)
{
	if (root->tree != NULL)
		free_tree(&(root->tree), 0);
	if (root->lexer != NULL)
		root->lexer = free_lexer(root->lexer);
	if (root->pipes)
		free(root->pipes);
	root->pipes = NULL;
	free(root->prompt);
	free(root->line);
}

void	free_all(t_root *root, int i)
{
	free_envp_lst(root);
	free_array(root->env_array);
	if (root->tree != NULL)
		free_tree(&(root->tree), 0);
	if (root->lexer != NULL)
		root->lexer = free_lexer(root->lexer);
	free(root->user);
	free(root->prompt);
	free(root->line);
	if (root->pipes)
		free(root->pipes);
	rl_clear_history();
	if (i == 0)
		printf("exit\n");
}
