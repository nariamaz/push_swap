/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_filling_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 20:13:34 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/31 20:41:35 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
	{
		printf("  (empty)\n");
		return ;
	}
	head = stack;
	printf("  [%d", stack->content);
	stack = stack->next;
	while (stack != head)
	{
		printf(", %d", stack->content);
		stack = stack->next;
	}
	printf("]\n");
}

static void	run_case(char *label, int argc, char **argv, int expect_error)
{
	t_stack	*stack_a;
	int		result;

	stack_a = NULL;
	printf("Test [%s]: ", label);
	result = ft_fill_stack(argc, argv, &stack_a);
	if (expect_error && !result)
		printf("PASS (error as expected)\n");
	else if (!expect_error && result)
	{
		printf("PASS -> ");
		print_stack(stack_a);
	}
	else
		printf("FAIL\n");
	if (stack_a)
		clean_list(&stack_a);
}

int	main(void)
{
	char	*args1[] = {"./push_swap", "1", "2", "3"};
	char	*args2[] = {"./push_swap", "1 2 3"};
	char	*args3[] = {"./push_swap", "--bench", "1", "2", "3"};
	char	*args4[] = {"./push_swap", "-5", "10", "-3"};
	char	*args5[] = {"./push_swap", "1", "2", "1"};
	char	*args6[] = {"./push_swap"};
	char	*args7[] = {"./push_swap", "--bench --simple", "1", "2"};
	char	*args8[] = {"./push_swap", "5", "3", "8", "1", "9"};
	char	*args9[] = {"./push_swap", "5", "3", "5", "1", "9"};

	run_case("sequencia simples", 4, args1, 0);
	run_case("token unico, varios numeros", 2, args2, 0);
	run_case("flag seguida de numeros", 5, args3, 0);
	run_case("numeros negativos", 4, args4, 0);
	run_case("numeros duplicados", 4, args5, 1);
	run_case("sem argumentos", 1, args6, 0);
	run_case("duas flags no mesmo token", 4, args7, 0);
	run_case("conjunto maior", 6, args8, 0);
	run_case("número repetido", 6, args9, 1);
	return (0);
}
