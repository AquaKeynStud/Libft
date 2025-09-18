/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:40:02 by arocca            #+#    #+#             */
/*   Updated: 2025/09/18 16:41:47 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_empty_line(char *line)
{
	if (!line || !*line)
		return (1);
	while (*line)
	{
		if (!ft_isspace(*line) && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}
