/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:25:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 09:24:56 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_STRUCTS_H
# define LISTS_STRUCTS_H

# include "../minishell.h"

typedef enum s_io
{
	STDIN,
	STDOUT,
	STDERR,
}	t_io;

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

typedef enum types
{
	pipem = 1,
	red_in = 2,
	red_out = 3,
	command = 4,
	file = 5,
	here_doc = 6,
	app_out = 7,
	s_quotes = 87,
	d_quotes = 82,
}	t_check;

typedef struct ast_tree
{
	int				node;
	int				type;
	int				*squotes;
	int				*dquotes;
	char			**command;
	char			*file;
	struct ast_tree	*left;
	struct ast_tree	*rigth;
	struct ast_tree	*prev;
}	t_ast;

typedef struct lexer_list
{
	char				*str;
	int					number;
	int					type;
	struct lexer_list	*next;
	struct lexer_list	*prev;
}	t_lexer;

typedef struct s_root
{
	t_lexer		*lexer;
	t_ast		*tree;
	char		**env_array;
	t_envlst	*env_lst;
	char		*user;
	char		*prompt;
	char		*line;
	int			in;
	int			out;
	int			isbuilt;
	int			*pipes;
	int			status;
	int			status_old;
	int			num_pipes;
	int			len;
	int			a;
	int			b;
	int			j;
	int			i;
}	t_root;

#endif