/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:00:56 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/16 21:27:39 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
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
