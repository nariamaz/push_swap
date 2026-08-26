#include <stdio.h>
#include "../../include/push_swap.h"

static void 	add_to_list(t_stack **lista, int new_content);
static void 	print_list(t_stack *stack);
static int		check_duplicate_n(t_stack *stack, int num);
static void		clean_list(t_stack **head); // TO FIX
static t_stack	*create_node(int new_content, t_stack *prev, t_stack *next);

int main(void)
{
	t_stack	*lista;

	lista = NULL;
	add_to_list(&lista, 8);
	add_to_list(&lista, 7);
	add_to_list(&lista, 6);
	add_to_list(&lista, 5);
	add_to_list(&lista, 4);
	// (void)add_to_list;
	print_list(lista);
	printf("Tem Duplicata: %s\n", check_duplicate_n(lista, 2) ? "True" : "False");
	// print_list(lista);
	(void)clean_list;
}

static void print_list(t_stack *head)
{
	t_stack	*iterator_node;

	iterator_node = head;
	if (iterator_node == NULL)
		printf("Lista Vazia\n");
	else if (iterator_node->next == NULL)
		printf("Conteúdo Único: \"%d\"\n", iterator_node->content);
	else
	{
		printf("Conteúdo: \"%d\"\n", iterator_node->content);
		iterator_node = iterator_node->next;
		while (iterator_node != head)
		{
			printf("Conteúdo: \"%d\"\n", iterator_node->content);
			iterator_node = iterator_node->next;
		}
	}
}

static void add_to_list(t_stack **head, int new_content)
{
	t_stack	*new_node;
	t_stack	*tail;

	if (*head == NULL)
		*head = create_node(new_content, NULL, NULL);
	else if ((*head)->next == NULL)
	{
		new_node = create_node(new_content, *head, *head);
		(*head)->next = new_node;
		(*head)->prev = new_node;
	}
	else
	{
		tail = (*head)->prev;
		new_node = create_node(new_content, tail, *head);
		tail->next = new_node;
		(*head)->prev = new_node;
	}
}

static int	check_duplicate_n(t_stack *stack, int num)
{
	t_stack	*tail;

	if (stack == NULL)
		return (0);
	else if (stack->next == NULL)
		return (stack->content == num);

	tail = stack->prev;
	tail->next = NULL;
	while (stack != NULL)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	clean_list(t_stack **head)
{
	t_stack *initial;
	t_stack	*iterator_node;

	initial = *head;
	iterator_node = *head;
	while (iterator_node != initial)
	{
		*head = iterator_node->next;
		free(iterator_node);
		iterator_node = *head;
	}
	*head = NULL;
}

static t_stack	*create_node(int new_content, t_stack *prev, t_stack *next)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	new_node->content = new_content;
	new_node->prev = prev;
	new_node->next = next;
	return(new_node);
}
