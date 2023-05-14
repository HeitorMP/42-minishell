/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:48:07 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/05/14 09:49:46 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

void	init_all(t_root *root, int argc, char const *argv[], char **envp)
{
	(void)argc;
	(void)argv;
	root->lexer = NULL;
	root->tree = NULL;
	root->env_array = NULL;
	root->env_lst = NULL;
	root->prompt = NULL;
	root->prompt = NULL;
	root->line = NULL;
	root->pipes = NULL;
	root->status = 0;
	root->status_old = 0;
	init_envp(root, envp);
	root->user = get_env_value(root, "USER");
}

void	get_status(t_root *root)
{
	if (g_status == 130)
		root->status_old = 130;
	else if (g_status == 131)
		root->status_old = 131;
	else
		root->status_old = root->status;
	g_status = 0;
}

static void	go_process(t_root *root)
{
	root->in = 0;
	root->out = 1;
	root->status = 0;
	root->status = checking_processes(root);
}

static int	is_empty_line(char *line, t_root *root)
{
	char	*trim_line;

	(void)root;
	trim_line = NULL;
	if (ft_strlen(line) > 0)
	{
		trim_line = ft_strtrim(line, " ");
		if (ft_strlen(trim_line) == 0)
		{
			free(root->prompt);
			free(root->line);
			root->line = NULL;
			root->prompt = NULL;
			free(trim_line);
			return (1);
		}
		free(trim_line);
	}
	return (0);
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_root	root;

	init_all(&root, argc, argv, envp);
	while (1)
	{
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
		root.prompt = get_prompt(&root);
		root.line = readline(root.prompt);
		if (root.line == NULL)
			break ;
		if (is_empty_line(root.line, &root))
			continue ;
		add_history(root.line);
		if (!lexical_annalysis(&root.lexer, root.line, &root))
		{
			root.tree = NULL;
			get_status(&root);
			if (!parsing_str(&root.lexer, &root.tree, &root))
				go_process(&root);
		}
		mini_free(&root);
	}
	free_all(&root, 0);
}
