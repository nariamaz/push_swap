/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:56:56 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/15 16:23:58 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char const *str, char ch);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int	    ft_isdigit(int c); 
void	ft_putstr_fd(char *s, int fd); 
char	**ft_split(char const *str, char ch); 
char	*ft_strdup(const char *s); 
size_t	ft_strlen(const char *s); 

