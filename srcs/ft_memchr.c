/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:43 by arocca            #+#    #+#             */
/*   Updated: 2025/09/08 10:32:37 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ucc;
	unsigned char	*str;

	i = 0;
	ucc = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == ucc)
			return (str + i);
		i++;
	}
	return (NULL);
}
