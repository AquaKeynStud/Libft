/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:37:15 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:44:42 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;

	if (!dest && !src)
		return (NULL);
	ndest = (char *)dest;
	nsrc = (const char *)src;
	while (n)
	{
		ndest[n - 1] = nsrc[n - 1];
		n--;
	}
	return (dest);
}
