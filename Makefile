# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/08/16 22:36:41 by maridos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
MAKEFLAGS	:=	--silent
AR			:=	ar -rcs
RM			:=	rm -rf

SRCS		:= 	libft/src/ft_calloc.c \
				libft/src/ft_isdigit.c \
				libft/src/ft_putstr_fd.c \
				libft/src/ft_split.c \
				libft/src/ft_strdup.c \
				libft/src/ft_strlen.c \
				libft/src/ft_strlcpy.c \
				libft/src/ft_memcpy.c \
				src/main.c
				
# HEADERS		:= libft/libft.h \
# 			   include/push_swap.h \
# 			   include/error.h

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
