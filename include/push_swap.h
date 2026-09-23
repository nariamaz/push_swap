/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:14:39 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/23 10:19:10 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

/* NUMBER FLAGS */
typedef enum e_flags
{
	BENCH,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	FLAG_COUNT
}	t_flags;

/* NUMBER OPERATIONS */
typedef enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_operations;

typedef struct s_stack	t_stack;
struct s_stack
{
	int		content;
	int		index;
	t_stack	*next;
	t_stack	*prev;
};

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_data
{
	double		disorder;
	int			f_counter[FLAG_COUNT];
	int			op_counter[OP_COUNT];
	int			total_nbs;
	int			strategy;
	int			strategy_selected;
	const char	*op_names[OP_COUNT];
}	t_data;

/* ARGUMENT DISPATCH */
int		ft_is_blank(char *str);
int		ft_validate_args(int argc, char **argv, t_data *data);
int		ft_has_number(char *argv);

/* VALIDATION NUMBER AND FLAGS*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_parsing(char *string, t_data *data);
int		ft_atoi(char **str);
int		ft_check_duplicate_f(t_data *data);
int		ft_check_overflow(char *start, int digits, int is_negative);
int		ft_validate_number(char **string, t_data *data);
int		ft_validate_flag(char *str, t_data *data);
int		ft_fill_stack(int argc, char **argv, t_stack **stack_a);

/* ERROR */
int		ft_print_error(void);

/* STACK */
void	add_to_list(t_stack **head, int new_content);
int		check_duplicate_n(t_stack *stack, int num);
void	clean_list(t_stack **stack);
void	print_list(t_stack *stack);
void	print_node(t_stack *node);

/* OPERATIONS */
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* METRICS */
void	ft_init_op_names(t_data *data);
int		ft_total_ops(t_data operations);
void	ft_compute_disorder(t_stack *stack, t_data *data);
void	ft_get_strategy(t_data *data, t_stacks *stacks);
void	ft_adaptive_strategy(t_stacks *stacks, t_data *data);
void	ft_print_counts(t_data data);
void	ft_show_benchmark(t_data data);

/* ALGORITHMS */
int		ft_find_min(t_stack *stack);
void	ft_assign_index(t_stack *stack, int total_nbs);
int		ft_calc_k(int total_nbs);
void	ft_do_op(t_operations op, t_stacks *stacks, t_data *data);
void	ft_sort_complex(t_stacks *stacks, t_data *data);
void	ft_sort_medium(t_stacks *stacks, t_data *data);
void	ft_sort_simple(t_stacks *stacks, t_data *data);
int		ft_find_max_in_chunk(t_stack *stack, int chunk_size, int b_size);
void	ft_do_op(t_operations op, t_stacks *stacks, t_data *data);
void	ft_sort_small(t_stacks *stacks, t_data *data);
void	ft_rotate_a_top(t_stacks *stacks, t_data *data, int pos, int total);
void	ft_sort_three(t_stacks *stacks, t_data *data);
int		ft_sqrt(int nb);
int		ft_find_min_pos(t_stack *stack, int size);
int		get_target_for_b(t_stacks *stacks);

/* TESTS */ // To be removed
int		check_list_integrity(t_stack *head);

#endif
