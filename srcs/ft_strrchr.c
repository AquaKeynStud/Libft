/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:56 by arocca            #+#    #+#             */
/*   Updated: 2025/09/08 10:35:17 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ucc;
	char			*str;
	char			*occur;

	occur = NULL;
	str = (char *)s;
	ucc = (unsigned char)c;
	while (*str)
	{
		if (*str == ucc)
			occur = str;
		str++;
	}
	if (ucc == '\0')
		return (str);
	return (occur);
}
