/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:33:31 by arocca            #+#    #+#             */
/*   Updated: 2025/09/18 18:35:30 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	double_free(void **ptr, size_t size_if_not_null_term)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	if (!size_if_not_null_term)
	{
		while (ptr[i])
			free(ptr[i++]);
	}
	else
	{
		while (i < size_if_not_null_term)
			free(ptr[i++]);
	}
	free(ptr);
}
