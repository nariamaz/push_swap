# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/08/17 22:44:26 by maridos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
LIBFT_DIR	= 	libft
LIBFT		= 	$(LIBFT_DIR)/libft.a
INCLUDES  	 = -Iinclude -I$(LIBFT_DIR)
MAKEFLAGS	:=	--silent
AR			:=	ar -rcs
RM			:=	rm -rf

# SRCS		:= 	libft/src/ft_calloc.c \
# 				libft/src/ft_isdigit.c \
# 				libft/src/ft_putstr_fd.c \
# 				libft/src/ft_split.c \
# 				libft/src/ft_strdup.c \
# 				libft/src/ft_strlen.c \
# 				libft/src/ft_strlcpy.c \
# 				libft/src/ft_memcpy.c \
# 				libft/src/ft_strjoin.c \
# 				src/main.c

DIR_PARSE = src/parse/

# Arquivos
SRC_MAIN = src/main.c
SRC_PARSE = $(DIR_PARSE)valid_args.c

# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE)

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
