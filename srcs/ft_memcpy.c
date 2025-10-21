/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:37:15 by arocca            #+#    #+#             */
/*   Updated: 2025/10/21 18:20:23 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdst;
	unsigned long		*ldst;
	const unsigned char	*csrc;
	const unsigned long	*lsrc;

	if (!dest && !src)
		return (NULL);
	ldst = (unsigned long *)dest;
	lsrc = (const unsigned long *)src;
	i = n / sizeof(unsigned long);
	while (i--)
		*ldst++ = *lsrc++;
	cdst = (unsigned char *)ldst;
	csrc = (const unsigned char *)lsrc;
	i = n % sizeof(unsigned long);
	while (i--)
		*cdst++ = *csrc++;
	return (dest);
}
