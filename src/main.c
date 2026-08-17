/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/16 22:11:07 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int ft_print_error()
{
    ft_putstr_fd("Error\n", 2);
    return (0);
}

// int main(int argc, char** argv)
// {
//     return (0);
// }

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
#include <stdio.h>
int main (int argc, char** argv)
{
    int retorno;
    retorno = (validate_nb_args(argc, &*argv));
    
    if (retorno == 0)
    {
        printf("programa não possui operações a fazer");
        return (0);    
    }
    else
        printf("vida que segue pra split");
    return (0);
}