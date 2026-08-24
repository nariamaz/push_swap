/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:14:39 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/24 02:34:05 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <limits.h>

typedef enum e_flags 
{
    BENCH,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE,
    FLAG_COUNT
}   t_flags;

typedef struct s_state
{
    int counter [FLAG_COUNT];
}   t_state;

/* PARSER */
int has_multiple_numbers(char* str);
int	validate_nb_args(int argc, char **argv);
char* ft_join_args(int argc, char** argv);

/* VALIDATION NUMBER AND FLAGS*/
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_parsing(char *string, t_state *flag);
int ft_validate_number(char **string);
long ft_atol(char **str);
int ft_check_overflow(long value);
int ft_validate_flag(char* str, t_state *flag);
int ft_check_duplicity(t_state *flag);

/* ERROR */
int ft_print_error();

#endif
