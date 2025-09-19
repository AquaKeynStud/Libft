/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:54:58 by arocca            #+#    #+#             */
/*   Updated: 2025/09/18 17:48:38 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPGRADE_H
# define UPGRADE_H

/* -- Includes -- */
# include <stdlib.h>
# include <stdbool.h>

/* -- Functions -- */
int		ft_isspace(int c);
int		is_empty_line(char *line);
int		ft_atoll(const char *nptr);
char	*get_word(char *str, int pos);
void	ft_trim(char **str, char *set);
int		count_words(char *str, char *charset);
char	**split_str(char *str, char *charset);
bool	in_str(char c, char *str, bool verif_alnum);
void	double_free(void **ptr, size_t size_if_not_null_term);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif