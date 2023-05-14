LIBFT = libft.a
OBJS = main.o \
	   envs/init_envs.o envs/env_utils.o envs/get_value.o envs/free_env_utils.o \
	   prompt/get_prompt.o prompt/prompt_utils.o \
	   built-in/built_cd.o built-in/built_echo.o  built-in/built_pwd.o built-in/built_exit.o built-in/built_in_router.o \
	   built-in/built_export.o built-in/built_unset.o built-in/built_env.o utils/utils.o built-in/echo_utils.o  utils/utils2.o\
	   signals/signal_handler.o exec_commands/command.o lexer/lexical.o lexer/lexer_part2.o lexer/lexer_utils.o lexer/lexer_utils2.o lexer/lexer_str.o \
	   lexer/lexer_part3.o exec_commands/simple.o exec_commands/check_expander.o pipes/pipes_utils.o pipes/pipes_red.o pipes/incomp_pipes.o \
	   pipes/pipes.o parsing/parsing.o parsing/parsing_utils.o parsing/parsing_utils2.o parsing/parsing_utils3.o lexer/lexer_str3.o lexer/lexer_str2.o lexer/lexer_str4.o \
	   errors_and_exit/error_exit.o errors_and_exit/free_pl.o redirects/redirects.o parsing/parsing_utils4.o exec_commands/expander_command.o exec_commands/expander_commands2.o exec_commands/expander_command1.o

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
GREEN		:=	\033[0;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1ms
CYAN		:=	\033[0;36m
NAME = minishell

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C libft
	@cp libft/$(LIBFT) $(LIBFT)
	@echo "$(GREEN) [Success] libft compilation."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline
	@echo "$(GREEN) [Success] minishell compilation.$(WHITE)"

clean:
	@$(MAKE) clean --no-print-directory -C libft
	@rm -rf $(OBJS)
	@echo "$(CYAN) [cleaned] minishell objects."

fclean: clean
	@$(MAKE) fclean --no-print-directory -C libft
	@rm -rf $(NAME) $(LIBFT)
	@echo "$(CYAN) [cleaned] minishell executable.$(WHITE)"

re: fclean all
