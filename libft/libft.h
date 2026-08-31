/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:56:56 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/17 15:51:19 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *str, char ch);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
