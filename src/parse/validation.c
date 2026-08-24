/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:58:58 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/24 19:03:21 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static const char *valid_flags[] = {
    "bench",
    "simple",
    "medium",
    "complex",
    "adaptive",
    NULL
};

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    
    i = 0;
    if (n == 0)
        return (0);
    while (i < n && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}    

int ft_parsing(char *string, t_state *flag)
{
    while (*string != '\0')
    {
        while (*string == ' ')
            string++;
        if (*string == '\0')
            break ;
        if (*string == '-' && *(string + 1) == '-')
        {
            string += 2;
            if (!ft_validate_flag(string, flag))
                return (0);
            while (*string != ' ' && *string != '\0')
                string++;
        }
        else if (*string == '+' || *string == '-' || ft_isdigit(*string))
        {
            if (!ft_validate_number(&string))
                return (0);
        }
        else
            return (ft_print_error());
    }
    return (1);
}

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

int ft_validate_flag(char* str, t_state *flag)
{
    int i;
    int len;
    
    i = 0;
    while (valid_flags[i] != NULL)
    {
        len = 0;
        while (valid_flags[i][len] != '\0')
            len++;
        if (ft_strncmp(valid_flags[i], str, len) == 0 && (str[len] == ' ' 
                || str[len] == '\0'))
        {
            flag->counter[i]++;
            return (1);
        }
        i++;
    }
    return (ft_print_error());
}
int ft_check_duplicity(t_state *flag)
{
    int i;
    int sum;
    
    i = 0;
    while (i < FLAG_COUNT)
    {
        if (flag->counter[i] > 1)
            return (ft_print_error());
        i++;
    }
    sum = (flag->counter[1] + flag->counter[2]
                + flag->counter[3] + flag->counter[4]);
    if (sum > 1)
        return (ft_print_error());
    return (1);
}