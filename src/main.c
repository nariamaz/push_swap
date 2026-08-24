/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/24 02:35:37 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int main(int argc, char** argv)
{
    char* str_argv;

    if (validate_nb_args(argc, &*argv))
    {
        str_argv = ft_join_args(argc, &*argv);
        t_state flag = {0};
        ft_parsing(str_argv, &flag);
        ft_check_duplicity(&flag);
    }
    else
        return (0);
    return (0);
}



