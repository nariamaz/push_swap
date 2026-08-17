/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 15:57:41 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/16 21:25:46 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	mksplit(char const *st, char c, size_t i, char **substr)
{
	char	*str;
	size_t	init;
	size_t	strlen;

	while (st[i])
	{
		if (st[i] && st[i] != c)
		{
			init = i;
			while (st[i] && st[i] != c)
				i++;
			strlen = (i - init) + 1;
			str = malloc(sizeof(char) * strlen);
			ft_strlcpy(str, &st[init], strlen);
			*(char **)(substr++) = str;
		}
		if (st[i] && st[i] == c)
			while (st[i] && st[i] == c)
				i++;
	}
	substr = NULL;
}

static size_t	ft_cntwords(char const *st, char ch)
{
	size_t	words;

	words = 0;
	while (*st)
	{
		if (*st && *st != ch)
		{
			while (*st && *st != ch)
				st++;
			words++;
		}
		if (*st && *st == ch)
			while (*st && *st == ch)
				st++;
	}
	return (words + 1);
}

char	**ft_split(char const *str, char ch)
{
	size_t	nb_words;
	char	**splited;

	if (!str)
		return (NULL);
	nb_words = ft_cntwords(str, ch);
	splited = ft_calloc((nb_words), sizeof(char *));
	if (!splited)
		return (NULL);
	mksplit(str, ch, 0, splited);
	return (splited);
}