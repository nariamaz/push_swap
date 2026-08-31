/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:16:28 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/25 17:12:15 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_number(char **string, t_state *flag)
{
	char	*start;
	int		is_negative;
	int		digits;

	is_negative = 0;
	start = *string;
	if (**string == '+' || **string == '-')
	{
		if (**string == '-')
			is_negative = 1;
		start++;
	}
	if (!ft_isdigit(*start))
		return (ft_print_error());
	digits = 0;
	while (ft_isdigit(start[digits]))
		digits++;
	if (start[digits] != ' ' && start[digits] != '\0')
		return (ft_print_error());
	if (!ft_check_overflow(start, digits, is_negative))
		return (0);
	flag->total_numbers++;
	*string = start + digits;
	return (1);
}

long	ft_atol(char **str)
{
	long	result;
	int		sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	result = 0;
	while (ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result * sign);
}

int	ft_check_overflow(char *start, int digits, int is_negative)
{
	char	*max;
	char	*min;

	max = "2147483647";
	min = "2147483648";
	if (digits > 10)
		return (ft_print_error());
	if (digits < 10)
		return (1);
	if (is_negative)
	{
		if (ft_strncmp(start, min, 10) > 0)
			return (ft_print_error());
	}
	else
	{
		if (ft_strncmp(start, max, 10) > 0)
			return (ft_print_error());
	}
	return (1);
}
