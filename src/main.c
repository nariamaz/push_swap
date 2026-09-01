/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/31 20:16:46 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	flag;
	t_stack *stack_a;
	
	flag = (t_state){0};
	stack_a = NULL;
	if (!ft_parse_arguments(argc, argv, &flag))
		return (0);
	if (!ft_check_duplicity(&flag))
		return (0);
	if (!ft_fill_stack(argc, argv, &stack_a))
		return (0);
	return (0);
}



