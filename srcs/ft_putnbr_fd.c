/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:32:24 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:38:42 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	digit;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb <= 9)
	{
		digit = '0' + nb;
		write(fd, &digit, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		digit = '0' + (nb % 10);
		write(fd, &digit, 1);
	}
	return ;
}
