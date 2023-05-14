# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 19:02:37 by idias-al          #+#    #+#              #
#    Updated: 2023/03/21 17:57:49 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS			=	ft_printf/ft_printf.o ft_printf/ft_printhexa.o ft_printf/ft_print_simple.o ft_printf/ft_printunsigned.o\
				ft_printf/ft_pointer.o ft_printf/ft_printf_float.o
OBJS_GNL		=	gnl/get_next_line.o gnl/get_next_line_utils.o gnl/get_next_line_bonus.o \
				   	gnl/get_next_line_utils_bonus.o
CC				= cc
RM				= rm -f
INCLUDES		= incs/
CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDES)
NAME			= libft.a

all:			$(NAME)

%.o:%.c
			@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS) $(OBJS_GNL)
				@$(MAKE) --no-print-directory -C libft
				@cp libft/$(NAME) $(NAME)
				@ar rcs $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_LIBFT)

clean:
				@$(MAKE) --no-print-directory clean -C libft
				@$(RM) $(OBJS) $(OBJS_LIBFT) $(OBJS_GNL)

fclean:			clean
				@$(MAKE) --no-print-directory fclean -C libft
				@$(RM) $(NAME)

re:				fclean $(NAME)

