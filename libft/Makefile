# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/08/17 22:14:41 by maridos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
MAKEFLAGS	:=	--silent
AR			:=	ar -rcs
RM			:=	rm -rf

SRCS		:= 	src/ft_calloc.c \
				src/ft_isdigit.c \
				src/ft_putstr_fd.c \
				src/ft_split.c \
				src/ft_strdup.c \
				src/ft_strlen.c \
				src/ft_strjoin.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
