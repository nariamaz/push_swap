/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:58:58 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/04 12:22:21 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_validate_flag(char *str, t_data *data)
{
	int					i;
	int					len;
	static const char	*valid_flags[] = {
		"bench", "simple", "medium", "complex", "adaptive", NULL
	};

	i = 0;
	while (valid_flags[i] != NULL)
	{
		len = 0;
		while (valid_flags[i][len] != '\0')
			len++;
		if (ft_strncmp(valid_flags[i], str, len) == 0 && (str[len] == ' '
				|| str[len] == '\0'))
		{
			data->f_counter[i]++;
			return (1);
		}
		i++;
	}
	return (ft_print_error());
}

int	ft_check_duplicate_f(t_data *data)
{
	int	i;
	int	sum;

	i = 0;
	while (i < FLAG_COUNT)
	{
		if (data->f_counter[i] > 1)
			return (ft_print_error());
		i++;
	}
	sum = (data->f_counter[BENCH] + data->f_counter[SIMPLE]
			+ data->f_counter[MEDIUM] + data->f_counter[COMPLEX]);
	if (sum > 1)
		return (ft_print_error());
	return (1);
}

