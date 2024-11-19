/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:49:56 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:45:26 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	ucc;
	char			*occur;

	str = (char *)s;
	ucc = (unsigned char)c;
	occur = NULL;
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
