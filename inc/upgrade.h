/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:58 by arocca            #+#    #+#             */
/*   Updated: 2025/09/18 17:46:45 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPGRADE_H
# define UPGRADE_H

/* -- Includes -- */
# include <stdbool.h>

/* -- Functions -- */
int		ft_isspace(int c);
int		is_empty_line(char *line);
int		ft_atoll(const char *nptr);
void	ft_trim(char **str, char *set);
char	**ft_split_str(char *str, char *charset);
bool	in_str(char c, char *str, bool verif_alnum);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif