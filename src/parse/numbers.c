/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:16:28 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/04 12:14:05 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_number(char **string, t_data *data)
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
	data->total_nbs++;
	*string = start + digits;
	return (1);
}

int ft_atoi(char **str)
{
    int result;
    int sign;

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

static int ft_extract_number(char *str, t_stack **stack_a)
{
    int num;

    while (*str != '\0')
    {
        if (*str == '-' && *(str + 1) == '-')
        {
            while (*str != ' ' && *str != '\0')
                str++;
        }
        else if (*str == '+' || *str == '-' || ft_isdigit(*str))
        {
            num = ft_atoi(&str);
            if (check_duplicate_n(*stack_a, num))
            {
                clean_list(stack_a);
                return (ft_print_error());
            }
            add_to_list(stack_a, num);
        }
        else
            str++;
    }
    return (1);
}

int ft_fill_stack(int argc, char **argv, t_stack **stack_a)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!ft_extract_number(argv[i], stack_a))
            return (0);
        i++;
    }
    return (1);
}
