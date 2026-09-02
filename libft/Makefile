# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/09/01 22:32:20 by maridos-         ###   ########.fr        #
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
				src/ft_strlen.c \
				src/ft_putnbr_fd.c \
				src/ft_putchar_fd.c

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
