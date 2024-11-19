/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:13:56 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:45:30 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_charset(const char *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	char			*start;
	unsigned int	len;

	len = 0;
	if (!s1)
		return (NULL);
	while (*s1 && check_charset(set, *s1))
		s1++;
	while (s1[len])
		len++;
	while (len > 0 && check_charset(set, s1[len - 1]))
		len--;
	res = (char *)malloc((sizeof(char) * len) + 1);
	if (!res)
		return (NULL);
	start = res;
	while (len--)
		*res++ = *s1++;
	*res = '\0';
	return (start);
}
