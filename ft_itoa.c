/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:20:40 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:44:16 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 1;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static long	make_lpos(int n)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
		return (nbr *= -1);
	else
		return (nbr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_nbr;
	long	pos_nbr;

	pos_nbr = make_lpos(n);
	digit_nbr = count_digit(n) - (n > 0);
	str = (char *)malloc(digit_nbr + 1);
	if (!str)
		return (NULL);
	str[digit_nbr] = '\0';
	while (digit_nbr--)
	{
		str[digit_nbr] = '0' + pos_nbr % 10;
		pos_nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
