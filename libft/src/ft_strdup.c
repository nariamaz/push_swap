/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:02:22 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/15 16:16:06 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_cast;
	unsigned char		*dest_cast;
	size_t				i;

	src_cast = (unsigned char *)src;
	dest_cast = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_size;
	size_t	len_copy;

	src_size = ft_strlen(src);
	if (dest_size == 0)
		return (src_size);
	if (dest_size <= src_size)
		len_copy = dest_size - 1;
	else
		len_copy = src_size;
	ft_memcpy(dest, src, len_copy);
	dest[len_copy] = '\0';
	return (src_size);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, (char *)s, len + 1);
	return (dup);
}
