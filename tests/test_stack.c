/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:32:33 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 18:08:41 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "push_swap.h"

#define BLACK		"\033[1;30m"
#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define WHITE		"\033[1;37m"
#define RESET		"\033[0m"

int	main(void)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		i;
	t_stack	*iter_node;

	list_a = NULL;
	printf(YELLOW "===== Stack Creation Tests =====\n\n" RESET);

	printf(CYAN "1." MAGENTA " Testing empty list: ");
	assert(list_a == NULL);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "2." MAGENTA " Testing 1 Node: ");
	add_to_list(&list_a, 1);
	assert(list_a->content == 1);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "3." MAGENTA " Testing 2 Nodes: ");
	add_to_list(&list_a, 1);
	add_to_list(&list_a, 2);
	assert(list_a->content == 1);
	assert(list_a->next->content == 2);
	assert(list_a->prev->content == 2);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "4." MAGENTA " Testing 3 Nodes: ");
	add_to_list(&list_a, 1);
	add_to_list(&list_a, 2);
	add_to_list(&list_a, 3);
	assert(list_a->content == 1);
	assert(list_a->next->content == 2);
	assert(list_a->prev->content == 3);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "5." MAGENTA " Testing 10 Nodes: ");
	i = 1;
	while (i <= 10)
		add_to_list(&list_a, i++);
	assert(list_a->content == 1);
	assert(list_a->next->content == 2);
	assert(list_a->prev->content == 10);
	i = 1;
	iter_node = list_a;
	while (i++ < 10)
		iter_node = iter_node->next;
	assert(iter_node == list_a->prev);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "6." MAGENTA " Testing 100 Nodes: ");
	i = 0;
	while (i < 100)
		add_to_list(&list_a, i++);
	assert(list_a->content == 0);
	assert(list_a->next->content == 1);
	assert(list_a->prev->content == 99);
	i = 1;
	iter_node = list_a;
	while (i++ < 100)
		iter_node = iter_node->next;
	assert(iter_node == list_a->prev);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "7." MAGENTA " Testing 1000 Nodes: ");
	i = 1000;
	while (i > 0)
		add_to_list(&list_a, i--);
	assert(list_a->content == 1000);
	assert(list_a->next->content == 999);
	assert(list_a->prev->content == 1);
	i = 1;
	iter_node = list_a;
	while (i++ < 1000)
		iter_node = iter_node->next;
	assert(iter_node == list_a->prev);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "8." MAGENTA " Testing 10000 Nodes: ");
	i = 0;
	while (i < 10000)
		add_to_list(&list_a, i++);
	assert(list_a->content == 0);
	assert(list_a->next->content == 1);
	assert(list_a->prev->prev->content == 9998);
	i = 1;
	iter_node = list_a;
	while (i++ < 10000)
		iter_node = iter_node->next;
	assert(iter_node == list_a->prev);
	i = 1;
	iter_node = list_a;
	while (i++ <= 5000)
		iter_node = iter_node->prev;
	assert(iter_node->content == 5000);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(YELLOW "\n===== Duplicity Tests =====\n\n" RESET);

	printf(CYAN "9." MAGENTA "\tlist: NULL\n");
	printf("\tsearch: 10\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list_a, 10) == false);

	printf(CYAN "10." MAGENTA "\tlist: [10]\n");
	add_to_list(&list_a, 10);
	printf("\tsearch: 10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list_a, 10) == true);

	printf(CYAN "11." MAGENTA "\tlist: [10]\n");
	printf("\tsearch: 20\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list_a, 20) == false);

	printf(CYAN "12." MAGENTA "\tlist: [10, 20, 30]\n");
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	printf("\tsearch: 10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list_a, 10) == true);

	printf(CYAN "13." MAGENTA "\tlist: [10, 20, 30]\n");
	printf("\tsearch: 20\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list_a, 20) == true);

	printf(CYAN "14." MAGENTA "\tlist: [10, 20, 30]\n");
	printf("\tsearch: 30\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list_a, 30) == true);

	printf(CYAN "15." MAGENTA "\tlist: [10, 20, 30]\n");
	printf("\tsearch: 40\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list_a, 40) == false);
	clean_list(&list_a);
	assert(list_a == NULL);

	printf(CYAN "16." MAGENTA "\tlist: [-10, 0, 10]\n");
	add_to_list(&list_a, -10);
	add_to_list(&list_a, 0);
	add_to_list(&list_a, 10);
	printf("\tsearch: -10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list_a, -10) == true);

	clean_list(&list_a);
	assert(list_a == NULL);

	printf(YELLOW "===== Operations Tests =====\n\n" RESET);

	printf(CYAN "17. " MAGENTA "SA with empty list: ");
	sa(&list_a);
	assert(list_a == NULL);
	assert(check_list_integrity(list_a));
	printf(GREEN "OK\n");

	printf(CYAN "18. " MAGENTA "SA with 1 Node: ");
	add_to_list(&list_a, 10);
	sa(&list_a);
	assert(list_a->content == 10);
	assert(check_list_integrity(list_a));
	printf(GREEN "OK\n");

	printf(CYAN "19. " MAGENTA "SA with 2 Nodes: ");
	add_to_list(&list_a, 20);
	sa(&list_a);
	assert(list_a->content == 20);
	assert(list_a->next->content == 10);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "20. " MAGENTA "SA and SB with 2+ Nodes: ");
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	sa(&list_a);
	assert(list_a->content == 20);
	assert(list_a->next->content == 10);
	assert(list_a->next->next->content == 30);
	sb(&list_a);
	assert(list_a->content == 10);
	assert(list_a->next->content == 20);
	assert(list_a->next->next->content == 30);
	assert(check_list_integrity(list_a));
	clean_list(&list_a);
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "21." MAGENTA " PA and PB with both Stacks empty: ");
	list_b = NULL;
	pa(&list_a, &list_b);
	assert(list_a == NULL);
	assert(list_b == NULL);
	pb(&list_a, &list_b);
	assert(list_a == NULL);
	assert(list_b == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "22." MAGENTA " PA with Stack A with 1 Node and Stack B empty: ");
	add_to_list(&list_a, 10);
	pa(&list_a, &list_b);
	assert(list_a->content == 10);
	assert(check_list_integrity(list_a));
	assert(list_b == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "23." MAGENTA " PA with Stack A empty and Stack B with 1 Node: ");
	clean_list(&list_a);
	add_to_list(&list_b, 10);
	pa(&list_a, &list_b);
	assert(list_a->content == 10);
	assert(check_list_integrity(list_a));
	assert(list_b == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "24." MAGENTA " PB with Stack A with 1 Node and Stack B empty: ");
	clean_list(&list_a);
	add_to_list(&list_a, 10);
	pb(&list_a, &list_b);
	assert(list_b->content == 10);
	assert(check_list_integrity(list_b));
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "25." MAGENTA " PB with Stack A empty and Stack B with 1 Node: ");
	clean_list(&list_b);
	add_to_list(&list_b, 10);
	pb(&list_a, &list_b);
	assert(list_b->content == 10);
	assert(check_list_integrity(list_b));
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "26." MAGENTA " PA with both Stacks with 1 Node: ");
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_b, 42);
	pa(&list_a, &list_b);
	assert(list_a->content == 42);
	assert(list_a->next->content == 10);
	assert(check_list_integrity(list_a));
	assert(list_b == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "27." MAGENTA " PB with both Stacks with 1 Node: ");
	clean_list(&list_a);
	add_to_list(&list_a, 10);
	add_to_list(&list_b, 42);
	pb(&list_a, &list_b);
	assert(list_b->content == 10);
	assert(list_b->next->content == 42);
	assert(check_list_integrity(list_b));
	assert(list_a == NULL);
	printf(GREEN "OK\n");

	printf(CYAN "28." MAGENTA " PA with Stack B with 2 Nodes and Stack A empty: ");
	clean_list(&list_b);
	add_to_list(&list_b, 10);
	add_to_list(&list_b, 42);
	pa(&list_a, &list_b);
	assert(list_a->content == 10);
	assert(list_b->content == 42);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "29." MAGENTA " PB with Stack A with 2 Nodes and Stack B empty: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 42);
	pb(&list_a, &list_b);
	assert(list_a->content == 42);
	assert(list_b->content == 10);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "30." MAGENTA " PA with Stack B with 2 Nodes and Stack A with 1 Node: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 333);
	add_to_list(&list_b, 10);
	add_to_list(&list_b, 20);
	pa(&list_a, &list_b);
	assert(list_a->content == 10);
	assert(list_a->next->content == 333);
	assert(list_b->content == 20);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "31." MAGENTA " PB with Stack A with 2 Nodes and Stack B with 1 Node: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_b, 333);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	pb(&list_a, &list_b);
	assert(list_b->content == 10);
	assert(list_b->next->content == 333);
	assert(list_a->content == 20);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "32." MAGENTA " PA with both Stacks with 2 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_b, 333);
	add_to_list(&list_b, 444);
	pa(&list_a, &list_b);
	assert(list_a->content == 333);
	assert(list_a->next->content == 10);
	assert(list_a->next->next->content == 20);
	assert(list_b->content == 444);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "33." MAGENTA " PB with both Stacks with 2 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_b, 333);
	add_to_list(&list_b, 444);
	pb(&list_a, &list_b);
	assert(list_a->content == 20);
	assert(list_b->content == 10);
	assert(list_b->next->content == 333);
	assert(list_b->next->next->content == 444);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "34." MAGENTA " PA with Stack A with 2 Nodes and Stack B with 3 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_b, 333);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	pa(&list_a, &list_b);
	assert(list_a->content == 333);
	assert(list_a->next->content == 10);
	assert(list_a->next->next->content == 20);
	assert(list_b->content == 444);
	assert(list_b->next->content == 555);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "35." MAGENTA " PA with Stack A with 3 Nodes and Stack B with 2 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	pa(&list_a, &list_b);
	assert(list_a->content == 444);
	assert(list_a->next->content == 10);
	assert(list_a->next->next->content == 20);
	assert(list_a->next->next->next->content == 30);
	assert(list_b->content == 555);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "36." MAGENTA " PB with Stack A with 2 Nodes and Stack B with 3 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_b, 333);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	pb(&list_a, &list_b);
	assert(list_a->content == 20);
	assert(list_b->content == 10);
	assert(list_b->next->content == 333);
	assert(list_b->next->next->content == 444);
	assert(list_b->next->next->next->content == 555);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "37." MAGENTA " PB with Stack A with 3 Nodes and Stack B with 2 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	pb(&list_a, &list_b);
	assert(list_a->content == 20);
	assert(list_a->next->content == 30);
	assert(list_b->content == 10);
	assert(list_b->next->content == 444);
	assert(list_b->next->next->content == 555);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "38." MAGENTA " PA with both Stacks with 3 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	add_to_list(&list_b, 666);
	pa(&list_a, &list_b);
	assert(list_a->content == 444);
	assert(list_a->next->content == 10);
	assert(list_a->next->next->content == 20);
	assert(list_a->next->next->next->content == 30);
	assert(list_b->content == 555);
	assert(list_b->next->content == 666);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "39." MAGENTA " PB with both Stacks with 3 Nodes: ");
	clean_list(&list_a);
	clean_list(&list_b);
	add_to_list(&list_a, 10);
	add_to_list(&list_a, 20);
	add_to_list(&list_a, 30);
	add_to_list(&list_b, 444);
	add_to_list(&list_b, 555);
	add_to_list(&list_b, 666);
	pb(&list_a, &list_b);
	assert(list_b->content == 10);
	assert(list_b->next->content == 444);
	assert(list_b->next->next->content == 555);
	assert(list_b->next->next->next->content == 666);
	assert(list_a->content == 20);
	assert(list_a->next->content == 30);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "40." MAGENTA " PA 40 times: ");
	clean_list(&list_a);
	clean_list(&list_b);
	i = 0;
	while (++i <= 100)
		add_to_list(&list_b, i);
	i = 0;
	while (i++ < 40)
		pa(&list_a, &list_b);
	assert(list_a->content == 40);
	assert(list_a->next->content == 39);
	assert(list_a->prev->content == 1);
	assert(list_b->content == 41);
	assert(list_b->next->content == 42);
	assert(list_b->prev->content == 100);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");

	printf(CYAN "41." MAGENTA " PB 200 times: ");
	clean_list(&list_a);
	clean_list(&list_b);
	i = 0;
	while (++i <= 100)
		add_to_list(&list_a, i);
	i = 0;
	while (i++ < 200)
		pb(&list_a, &list_b);
	assert(list_a == NULL);
	assert(list_b->content == 100);
	assert(list_b->next->content == 99);
	assert(list_b->prev->content == 1);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
	printf(GREEN "OK\n");
	
	printf(RESET);
	clean_list(&list_a);
	clean_list(&list_b);
	assert(check_list_integrity(list_a));
	assert(check_list_integrity(list_b));
}
