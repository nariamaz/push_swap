# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/08/27 18:06:05 by hequeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
LIBFT_DIR	= 	libft
LIBFT		= 	$(LIBFT_DIR)/libft.a
INCLUDES  	 = -Iinclude -I$(LIBFT_DIR)
MAKEFLAGS	:=	--silent
RM			:=	rm -f

# Diretórios
DIR_PARSE = src/parse/
DIR_ERROR = src/error/
DIR_STACK = src/stack/
DIR_OPS	  = src/operations/
DIR_TESTS = tests/

# Arquivos
SRC_MAIN = src/main.c
SRC_PARSE = $(DIR_PARSE)dispatcher.c \
			$(DIR_PARSE)flags.c \
			$(DIR_PARSE)numbers.c
SRC_ERROR = $(DIR_ERROR)error.c
SRC_STACK = $(DIR_STACK)stack_add.c \
			$(DIR_STACK)stack_check.c \
			$(DIR_STACK)stack_free.c \
			$(DIR_STACK)stack_print.c
SRC_OPS   = $(DIR_OPS)ops_swap.c \
			$(DIR_OPS)ops_push.c \
			$(DIR_OPS)ops_rotate.c \
			$(DIR_OPS)ops_reverse_rotate.c

# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE) $(SRC_ERROR) $(SRC_STACK) $(SRC_OPS)

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re libft

libft:
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

# Stack related
SRCS_TESTS = $(DIR_TESTS)test_stack.c \
			 $(SRC_PARSE) \
			 $(SRC_ERROR) \
			 $(SRC_STACK) \
			 $(SRC_OPS)

OBJS_TESTS = $(SRCS_TESTS:.c=.o)

test_stack: libft $(OBJS_TESTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_TESTS) -L$(LIBFT_DIR) -lft -o test_stack
	valgrind --leak-check=full --show-leak-kinds=all ./test_stack
