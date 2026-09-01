/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 21:52:52 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/31 11:35:48 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_arguments(int argc, char **argv, t_state *flag)
{
	int	i;
	int	found_number;

	if (argc < 2)
		return (1);
	found_number = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_is_blank(argv[i]))
			return (ft_print_error());
		if (!ft_parsing(argv[i], flag))
			return (0);
		if (ft_has_number(argv[i]))
			found_number = 1;
		i++;
	}
	if (!found_number)
		return (ft_print_error());
	return (1);
}

int	ft_parsing(char *string, t_state *flag)
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
			if (!ft_validate_number(&string, flag))
				return (0);
		}
		else
			return (ft_print_error());
	}
	return (1);
}

int	ft_is_blank(char *str)
{
	while (*str == ' ')
		str++;
	return (*str == '\0');
}

int	ft_has_number(char *argv)
{
	while (*argv != '\0')
	{
		if (ft_isdigit(*argv))
			return (1);
		argv++;
	}
	return (0);
}
