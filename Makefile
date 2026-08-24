# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/08/24 00:49:35 by maridos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
LIBFT_DIR	= 	libft
LIBFT		= 	$(LIBFT_DIR)/libft.a
INCLUDES  	 = -Iinclude -I$(LIBFT_DIR)
MAKEFLAGS	:=	--silent
AR			:=	ar -rcs
RM			:=	rm -rf

DIR_PARSE = src/parse/

# Arquivos
SRC_MAIN = src/main.c
SRC_PARSE = $(DIR_PARSE)validation.c \
			$(DIR_PARSE)count_nb_args.c

# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE)

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft

libft:
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): libft $(OBJS)
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

