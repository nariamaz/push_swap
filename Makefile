# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/15 15:56:40 by maridos-          #+#    #+#              #
#    Updated: 2026/09/22 15:51:27 by maridos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
LIBFT_DIR	= 	libft
LIBFT		= 	$(LIBFT_DIR)/libft.a
INCLUDES  	 = -Iinclude -I$(LIBFT_DIR)
RM			:=	rm -f

# Diretórios
DIR_PARSE 		= src/parse/
DIR_ERROR 		= src/error/
DIR_STACK 		= src/stack/
DIR_OPS	  		= src/operations/
DIR_METRICS 	= src/metrics/
DIR_TESTS 		= tests/
DIR_COMMON		= src/algorithms/common/
DIR_ALGORITHMS 	= src/algorithms/

# Arquivos
SRC_MAIN = src/main.c
SRC_PARSE 		= $(DIR_PARSE)dispatcher.c \
				  $(DIR_PARSE)flags.c \
				  $(DIR_PARSE)numbers.c
SRC_ERROR 		= $(DIR_ERROR)error.c
SRC_STACK 		= $(DIR_STACK)stack_add.c \
				  $(DIR_STACK)stack_check.c \
				  $(DIR_STACK)stack_free.c \
				  $(DIR_STACK)stack_print.c
SRC_OPS   		= $(DIR_OPS)ops_swap.c \
				  $(DIR_OPS)ops_push.c \
				  $(DIR_OPS)ops_rotate.c \
				  $(DIR_OPS)ops_reverse_rotate.c
SRC_METRICS 	= $(DIR_METRICS)benchmark.c \
				  $(DIR_METRICS)strategy.c \
				  $(DIR_METRICS)operations.c 
SRC_COMMON		= $(DIR_COMMON)utils.c
SRC_ALGORITHMS	= $(DIR_ALGORITHMS)complex.c \
				  $(DIR_ALGORITHMS)medium.c \
				  $(DIR_ALGORITHMS)simple.c \
				  $(DIR_ALGORITHMS)small_sort.c \
				  $(DIR_ALGORITHMS)medium_helpers.c
				  
# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE) $(SRC_ERROR) $(SRC_STACK) $(SRC_OPS) \
		$(SRC_METRICS) $(SRC_COMMON) $(SRC_ALGORITHMS)

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re

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
SRC_TEST_STACK = $(DIR_TESTS)test_stack.c
SRC_TEST_FILL  = $(DIR_TESTS)test_filling_stack.c

SRCS_COMMON_TEST = $(SRC_PARSE) $(SRC_ERROR) $(SRC_STACK) $(SRC_OPS)

OBJS_TEST_STACK = $(SRC_TEST_STACK:.c=.o) $(SRCS_COMMON_TEST:.c=.o)
OBJS_TEST_FILL  = $(SRC_TEST_FILL:.c=.o) $(SRCS_COMMON_TEST:.c=.o)

test_stack: libft $(OBJS_TEST_STACK)
	$(CC) $(CFLAGS) $(OBJS_TEST_STACK) -L$(LIBFT_DIR) -lft -o test_stack
	valgrind --leak-check=full --show-leak-kinds=all ./test_stack

test_fill_stack: libft $(OBJS_TEST_FILL)
	$(CC) $(CFLAGS) $(OBJS_TEST_FILL) -L$(LIBFT_DIR) -lft -o test_fill_stack
	valgrind --leak-check=full --show-leak-kinds=all ./test_fill_stack
