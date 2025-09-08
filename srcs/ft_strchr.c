/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:19:12 by arocca            #+#    #+#             */
/*   Updated: 2025/09/08 10:34:02 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ucc;
	char			*str;

	str = (char *)s;
	ucc = (unsigned char)c;
	while (*str)
	{
		if (*str == ucc)
			return (str);
		str++;
	}
	if (ucc == '\0')
		return (str);
	return (NULL);
}
