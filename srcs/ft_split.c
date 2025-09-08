/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:59:30 by arocca            #+#    #+#             */
/*   Updated: 2025/09/08 10:33:54 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char	**tab)
{
	unsigned int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count += 1;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*split_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((sizeof(char) * len) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[i] = split_word(s, c);
			if (!res[i])
				return (free_split(res));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
