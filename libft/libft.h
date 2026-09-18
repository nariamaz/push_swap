/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:56:56 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/01 16:23:11 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif // LIBFT_H
