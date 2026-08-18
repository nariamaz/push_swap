/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 21:52:52 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/17 22:41:40 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int ft_print_error()
{
    ft_putstr_fd("Error\n", 2);
    return (0);
}

int	validate_nb_args(int argc, char **argv)
{
	int	j;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
            return(ft_print_error());
		if (has_multiple_numbers(argv[1]))
			return (1);
		j = 0;
		if (argv[1][j] == '+' || argv[1][j] == '-')
			j++;
		if (!argv[1][j])
            return(ft_print_error());
		while (argv[1][j])
		{
			if (!ft_isdigit(argv[1][j]))
                return(ft_print_error());
			j++;
		}
		return (0);
	}
    return (1);
}
int has_multiple_numbers(char* str)
{
    int space;
    int numbers;
    int i;

    space = 0;
    numbers = 0;
    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
        {
            numbers++;
            while (str[i] && ft_isdigit(str[i]))
                i++;
        }
        else
        {
            if (str[i] == ' ')
                space++;
            i++;
        }
    }
    if (space >=1 && numbers >= 2)
        return (1);
    return (0);
}

char* ft_join_args(int argc, char** argv)
{
    int i;
    char* full_str;
    char* tmp;

    full_str = NULL;
    i = 1;
    while (i < argc)
    {
        tmp = full_str;
        full_str = ft_strjoin(tmp, argv[i]);
        free (tmp);
        tmp = full_str;
        full_str = ft_strjoin (tmp, " ");
        free(tmp);
        i++;
    }
    return (full_str);
}
