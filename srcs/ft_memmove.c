/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:37:19 by arocca            #+#    #+#             */
/*   Updated: 2025/09/08 10:33:09 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*nsrc;
	char	*ndest;

	if (!dest && !src)
		return (NULL);
	nsrc = (char *)src;
	ndest = (char *)dest;
	if (nsrc < ndest && ndest < nsrc + n)
	{
		ndest += n;
		nsrc += n;
		while (n--)
			*(--ndest) = *(--nsrc);
	}
	else
	{
		while (n--)
			*ndest++ = *nsrc++;
	}
	return (dest);
}
