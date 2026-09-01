/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:50:15 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/17 22:13:20 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	define_str_size(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	return (len1 + len2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	if (!define_str_size(s1, s2))
		return (NULL);
	string = ft_calloc((define_str_size(s1, s2) + 1), sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			string[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	return (string);
}
