/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:14:39 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/31 12:08:36 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef enum e_flags
{
	BENCH,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	FLAG_COUNT
}	t_flags;

typedef struct s_state
{
	int	counter [FLAG_COUNT];
	int	total_numbers;
}	t_state;

typedef struct s_stack t_stack;
struct s_stack
{
	int		content;
	t_stack	*next;
	t_stack	*prev;
};

/* ARGUMENT DISPATCH */
int		ft_is_blank(char *str);
int		ft_parse_arguments(int argc, char **argv, t_state *flag);
int		ft_has_number(char *argv);

/* VALIDATION NUMBER AND FLAGS*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_parsing(char *string, t_state *flag);
int		ft_atoi(char **str);
int		ft_check_duplicity(t_state *flag);
int		ft_check_overflow(char *start, int digits, int is_negative);
int		ft_validate_number(char **string, t_state *flag);
int		ft_validate_flag(char *str, t_state *flag);
int 	ft_fill_stack(int argc, char** argv, t_stack **stack_a);

/* ERROR */
int		ft_print_error(void);

/* STACK */
void	add_to_list(t_stack **head, int new_content);
int		check_duplicate_n(t_stack *stack, int num);
void	clean_list(t_stack **stack);
void	print_list(t_stack *stack);
void	print_node(t_stack *node);

/* OPERATIONS */
void	sa(t_stack	**stack);
void	sb(t_stack	**stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* TESTS */ // To be removed
int		check_list_integrity(t_stack *head);

#endif
