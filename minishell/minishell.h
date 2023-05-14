/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:08:03 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/03 10:51:09 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include "libft/incs/libft.h"
# include "libft/incs/ft_printf.h"
# include "libft/incs/get_next_line.h"
# include "incs/parse_lexer.h"
# include "incs/lists_structs.h"
# include "incs/exec_redirects.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_PATH 4000

/* env funcs*/

void		init_envp(t_root *root, char **envp);
void		print_envlsts(t_root *root);
void		ft_lstadd_back_env(t_envlst **envs, t_envlst *new);
t_envlst	*ft_lstlast_envlst(t_envlst *envs);
t_envlst	*ft_lstnew_env(char *key, char *value);
void		free_envp_lst(t_root *root);
void		free_envp_array(t_root *root);
void		refresh_env_array(t_root *root);
int			get_array_size(char **array);
int			get_lst_size(t_envlst *lst);
char		*ft_strjoin_gnl(char *s1, char *s2);
int			print_env_value(t_root *root, char *key);
char		*get_env_value(t_root *root, char *key);
int			change_value(t_root *root, char *key, char *new_value);
char		*get_value_from_str(char *env);
char		*get_key_from_str(char *env);
void		free_array(char **array);
void		free_env_node(t_envlst *node);

/*utils*/
char		*transform(char cwd[]);
int			is_equal(char *command, char *key);
char		*get_pwd(void);

/*signal*/
void		sig_int(int sig);
void		sig_int2(int sig);
void		sig_quit(int sig);

/*prompt*/
void		redisplay_prompt(void);
char		*get_prompt(t_root *root);

/*built in*/
int			built_in_router(t_root *root);
int			cd(t_root *root);
int			echo(t_root *root);
int			pwd(t_root *root);
int			export(t_root *root);
int			unset(t_root *root);
int			env(t_root *root);
int			ft_exit(t_root *root);

/*error_exit file*/
int			e_pro(char *str, t_ast *node, int error, int type);
int			e_pro_fork(char *str, t_root *r, int error, int type);
void		free_tree(t_ast **t, int a);
void		free_str_split(char **str);
void		close_fd(t_ast *tree, int *pipes);
int			error_syntax(char *str, int error);
t_lexer		*free_lexer(t_lexer *lexer);
void		free_all(t_root *root, int i);
void		mini_free(t_root *root);

/*main*/
void		checking_next_node(t_ast **tree);

/*main heitor*/
int			is_built(char **commands, int i);

#endif
