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

int	main(void)
{
	t_stack	*list;
	int		i;
	t_stack	*iter_node;

	list = NULL;
	printf("===== Stack Creation Tests =====\n\n");

	printf("1. Testing empty list: ");
	assert(list == NULL);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("2. Testing 1 Node: ");
	add_to_list(&list, 1);
	assert(list->content == 1);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("3. Testing 2 Nodes: ");
	add_to_list(&list, 1);
	add_to_list(&list, 2);
	assert(list->content == 1);
	assert(list->next->content == 2);
	assert(list->prev->content == 2);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("4. Testing 3 Nodes: ");
	add_to_list(&list, 1);
	add_to_list(&list, 2);
	add_to_list(&list, 3);
	assert(list->content == 1);
	assert(list->next->content == 2);
	assert(list->prev->content == 3);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("5. Testing 10 Nodes: ");
	i = 1;
	while (i <= 10)
		add_to_list(&list, i++);
	assert(list->content == 1);
	assert(list->next->content == 2);
	assert(list->prev->content == 10);
	i = 1;
	iter_node = list;
	while (i++ < 10)
		iter_node = iter_node->next;
	assert(iter_node == list->prev);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("6. Testing 100 Nodes: ");
	i = 0;
	while (i < 100)
		add_to_list(&list, i++);
	assert(list->content == 0);
	assert(list->next->content == 1);
	assert(list->prev->content == 99);
	i = 1;
	iter_node = list;
	while (i++ < 100)
		iter_node = iter_node->next;
	assert(iter_node == list->prev);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("7. Testing 1000 Nodes: ");
	i = 1000;
	while (i > 0)
		add_to_list(&list, i--);
	assert(list->content == 1000);
	assert(list->next->content == 999);
	assert(list->prev->content == 1);
	i = 1;
	iter_node = list;
	while (i++ < 1000)
		iter_node = iter_node->next;
	assert(iter_node == list->prev);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("8. Testing 10000 Nodes: ");
	i = 0;
	while (i < 10000)
		add_to_list(&list, i++);
	assert(list->content == 0);
	assert(list->next->content == 1);
	assert(list->prev->prev->content == 9998);
	i = 1;
	iter_node = list;
	while (i++ < 10000)
		iter_node = iter_node->next;
	assert(iter_node == list->prev);
	i = 1;
	iter_node = list;
	while (i++ <= 5000)
		iter_node = iter_node->prev;
	assert(iter_node->content == 5000);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	printf("\n\n===== Duplicity Tests =====\n\n");

	printf("9.\tlist: NULL\n");
	printf("\tsearch: 10\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list, 10) == false);

	add_to_list(&list, 10);
	printf("10.\tlist: [10]\n");
	printf("\tsearch: 10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list, 10) == true);

	printf("11.\tlist: [10]\n");
	printf("\tsearch: 20\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list, 20) == false);

	add_to_list(&list, 20);
	add_to_list(&list, 30);
	printf("12.\tlist: [10, 20, 30]\n");
	printf("\tsearch: 10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list, 10) == true);

	printf("13.\tlist: [10, 20, 30]\n");
	printf("\tsearch: 20\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list, 20) == true);

	printf("14.\tlist: [10, 20, 30]\n");
	printf("\tsearch: 30\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list, 30) == true);

	printf("15.\tlist: [10, 20, 30]\n");
	printf("\tsearch: 40\n");
	printf("\tresult: false\n\n");
	assert(check_duplicate_n(list, 40) == false);
	clean_list(&list);
	assert(list == NULL);

	add_to_list(&list, -10);
	add_to_list(&list, 0);
	add_to_list(&list, 10);
	printf("16.\tlist: [-10, 0, 10]\n");
	printf("\tsearch: -10\n");
	printf("\tresult: true\n\n");
	assert(check_duplicate_n(list, -10) == true);

	clean_list(&list);
	assert(list == NULL);

	printf("===== Operations Tests =====\n\n");

	printf("17. SA with empty list: ");
	sa(&list);
	assert(list == NULL);
	assert(check_list_integrity(list));
	printf("OK\n");

	add_to_list(&list, 10);
	printf("18. SA with 1 Node: ");
	sa(&list);
	assert(list->content == 10);
	assert(check_list_integrity(list));
	printf("OK\n");

	add_to_list(&list, 20);
	printf("19. SA with 2 Nodes: ");
	sa(&list);
	assert(list->content == 20);
	assert(list->next->content == 10);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	add_to_list(&list, 10);
	add_to_list(&list, 20);
	add_to_list(&list, 30);
	printf("20. SA and SB with 2+ Nodes: ");
	sa(&list);
	assert(list->content == 20);
	assert(list->next->content == 10);
	assert(list->next->next->content == 30);
	sb(&list);
	assert(list->content == 10);
	assert(list->next->content == 20);
	assert(list->next->next->content == 30);
	assert(check_list_integrity(list));
	clean_list(&list);
	assert(list == NULL);
	printf("OK\n");

	return (0);
}
