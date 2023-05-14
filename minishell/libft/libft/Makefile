# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 19:02:37 by idias-al          #+#    #+#              #
#    Updated: 2023/03/21 17:54:29 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	part1/ft_isalnum.c part1/ft_isalpha.c part1/ft_isascii.c part1/ft_isdigit.c \
					part1/ft_isprint.c part1/ft_memcmp.c part2/ft_putchar_fd.c part2/ft_split.c \
					part1/ft_strlcat.c part1/ft_strncmp.c part2/ft_substr.c part1/ft_atoi.c  \
					part2/ft_itoa.c part1/ft_memcpy.c part2/ft_putendl_fd.c part1/ft_strchr.c part1/ft_strlcpy.c \
					part1/ft_strnstr.c part1/ft_tolower.c part1/ft_bzero.c  part2/ft_strmapi.c\
					part1/ft_memmove.c part2/ft_putnbr_fd.c part1/ft_strdup.c part1/ft_strlen.c part1/ft_strrchr.c \
					part1/ft_toupper.c part1/ft_calloc.c  part1/ft_memchr.c part1/ft_memset.c  \
					part2/ft_putstr_fd.c part2/ft_strjoin.c part2/ft_strtrim.c part2/ft_striteri.c
OBJS			= $(SRCS:.c=.o)

BONUS			=	linked_lists/ft_lstadd_back.c linked_lists/ft_lstadd_front.c linked_lists/ft_lstclear.c \
				linked_lists/ft_lstdelone.c linked_lists/ft_lstiter.c linked_lists/ft_lstlast.c \
				linked_lists/ft_lstmap.c linked_lists/ft_lstnew.c linked_lists/ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)
INCLUDES		= ../incs/
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDES)
NAME			= libft.a
GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1ms

all:			$(NAME)

%.o:%.c
			@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				
bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

