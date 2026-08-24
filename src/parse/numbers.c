/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:16:28 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/24 19:18:01 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int ft_validate_number(char **string)
{
    char *start;
    long value;

    start = *string;
    if (**string == '+' || **string == '-')
        start++;
    if (!ft_isdigit(*start))
        return (ft_print_error());
    value = ft_atol(string);
    if (**string != ' ' && **string != '\0')
        return (ft_print_error());    
    if (!ft_check_overflow(value))
        return (0);
    return (1);
}

long ft_atol(char **str)
{
    long result;
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

int ft_check_overflow(long value)
{
    if (value > INT_MAX || value < INT_MIN)
        return (ft_print_error());
    return (1);
}