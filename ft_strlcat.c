/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:21 by arocca            #+#    #+#             */
/*   Updated: 2024/11/14 18:48:10 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	len_d = j;
	len_s = ft_strlen(src);
	if (size == 0 || size <= len_d)
		return (len_s + size);
	while (src[i] && i < size - len_d - 1)
	{
		dst[j] = src [i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_d + len_s);
}
