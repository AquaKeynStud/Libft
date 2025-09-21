/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:39:20 by arocca            #+#    #+#             */
/*   Updated: 2025/09/07 23:14:29 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	strict_pos_atoi(const char *nptr)
{
	unsigned long long	res;

	res = 0;
	if (!nptr || !*nptr || ((*nptr > '9' || *nptr < '0') && *nptr != '+'))
		return (-1);
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - '0');
		if (res > INT_MAX)
			return (-1);
	}
	if (*nptr != '\0')
		return (-1);
	return ((int)res);
}
