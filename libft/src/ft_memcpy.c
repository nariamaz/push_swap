/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:32:18 by maridos-          #+#    #+#             */
/*   Updated: 2026/06/04 19:42:32 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
