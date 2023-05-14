/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lexer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:21:16 by idias-al          #+#    #+#             */
/*   Updated: 2023/05/14 09:49:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LEXER_H
# define PARSE_LEXER_H

# include "../minishell.h"
# include "lists_structs.h"

/*==============parsing=========================================*/
/*parsing.c*/
int		first_objects(t_lexer **lexer, t_ast **tree);
int		when_pipe(t_lexer **lexer, t_ast **tree);
void	finish_parse(t_lexer **lexer, t_ast **tree);
int		second_loop(t_lexer **l, t_ast **t);
int		parsing_str(t_lexer **l, t_ast **t, t_root *r);
/*parsing utils*/
int		get_file(t_lexer **lexer, t_ast *node);
int		pipes_lexer(t_lexer *lexer);
int		length_lexer(t_lexer *lexer, t_ast *aux, int i);
char	**newstring(t_lexer **lexer, t_ast **tree);
char	**treat_string(t_lexer **lexer, t_ast **aux, t_ast **tree);
void	print_tree(t_ast *node, int i);
/*parsing uitls2*/
int		check_nodespart2(t_ast *tree, t_lexer *lexer, int red);
int		checking_nodes(t_ast *tree, t_lexer *lexer, int i);
int		is_file(int i);
void	array_quotes(t_ast **tree, t_lexer **lexer, int j);
char	**create_array(t_lexer **lexer, int len, t_ast **tree);
/*parsing utils 3*/
void	find_filecomand(t_lexer **lexer, t_ast **aux, int check, \
t_ast **node);
t_ast	*create_treenode(t_lexer **lexer, t_ast **aux, int check);
void	passing_file(t_lexer **lexer);
int		leftnode_file(t_lexer **lexer, t_ast **tree, int i);
int		when_file(t_lexer **lexer, t_ast **tree);
/*parsing4*/
t_ast	*create_nodeaux(t_ast **tree, int check);

/*===================lexical=====================================*/
/*lexical*/
t_lexer	*first_node(char *main, int *i, char **test);
int		check_firstnode(char *main, int *i, t_lexer **node);
void	add_index(t_lexer **node, char **str);
int		start_lexer(char **str, char *line, int *i, t_lexer **node, t_root *r);
int		lexical_annalysis(t_lexer **node, char *line, t_root *r);

/*lexer_utils*/
t_lexer	*lexical_node(char *str, int i, int j);
int		endofquotes(char s);
int		endofstring(char s);
int		node_type(t_lexer *node, char s);
int		closing_q(char *str, char c, int i, int *a);
/*lexer_utils2*/
int		check_signal1(char *main, int *i, t_lexer **node);
int		check_signal(char *main, int *i, t_lexer **node);
int		closing_q2(char *str, char c, int i, int len);
t_lexer	*sign_node(int *i, char s, char *str);
int		closing_q2(char *str, char c, int i, int len);
char	*lexer_strjoin(char *s1, char *s2);

/*lexer_part2*/
t_lexer	*treating_quotes(char *str, char s, int *b);
t_lexer	*nodes_split2(char **split, char s, int i, int a);
t_lexer	*nodes_split(char *test, char s, int a);

/*lexer part3*/
int		check_spaces(char *test);
t_lexer	*node_str(char *str, int *i, int j);
int		split_check(char **split);

/*lexer_ str*/
char	*find_string(char *line, int *i, int len);
char	*create_string(char *line);
char	*add_quotes(char s, char *aux);
char	*start_str(char *line, int *i, int len);
char	*aux_quotes(char *line, int *i, int len, char s);
char	*mid_str(char *line, int *i, char *str, int len);
char	*complete_strlexer(char *str, char *aux);
char	change_q(char s);
char	*create_string3(char *line, int *i, int len);
char	*create_string2(char *line, int len);
char	*create_string(char *line);
int		aux_space(char *aux);
char	*treat_begin(char *line, int len);
char	*treat_end(char *line, int len, int i);

char	*create_string4(char *line, int *i, int len, char *s);
char	*final_aux(char *line, char *aux, int len, int *i);

/*lexer_str4*/
t_lexer	*treating_quotes2(char s, char *test);
int		get_lenlexer(char *str, char s);
int		check_signal3(char **str, int *i, t_lexer **node);

#endif
