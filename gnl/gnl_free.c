/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:32:07 by arocca            #+#    #+#             */
/*   Updated: 2025/10/08 10:43:07 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_get_next_line(t_fd_list **head)
{
	t_fd_list	*next;
	t_fd_list	*current;

	if (!head || !*head)
		return (NULL);
	current = *head;
	while (current)
	{
		next = current->next;
		if (current->buffer)
			free(current->buffer);
		free(current);
		current = next;
	}
	*head = NULL;
	return (NULL);
}
