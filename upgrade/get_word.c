/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:42:32 by arocca            #+#    #+#             */
/*   Updated: 2025/09/22 16:18:22 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "upgrade.h"

char	*get_word(char *str, int pos)
{
	char	*word;
	char	**split;

	if (!str || pos < 0)
		return (NULL);
	if (count_words(str, " \t\n\v\f\r") < pos)
		pos = count_words(str, " \t\n\v\f\r");
	split = split_str(str, " \t\n\v\f\r");
	if (!split || !*split)
		return (NULL);
	if (split[pos])
	{
		word = ft_strdup(split[pos]);
		double_free((void **)split, 0);
		if (!word)
			return (NULL);
		return (word);
	}
	double_free((void **)split, 0);
	return (NULL);
}