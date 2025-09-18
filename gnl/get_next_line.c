/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:00:37 by arocca            #+#    #+#             */
/*   Updated: 2025/09/17 00:19:17 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "get_next_line.h"

t_fd_list	*get_node(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new;

	current = *head;
	while (current)
	{
		if (current -> fd == fd)
			return (current);
		current = current->next;
	}
	new = malloc(sizeof(t_fd_list));
	if (!new)
		return (NULL);
	new -> fd = fd;
	new -> buffer = NULL;
	new -> next = *head;
	*head = new;
	return (new);
}

char	*free_node(t_fd_list **head, int fd)
{
	t_fd_list	*previous;
	t_fd_list	*current;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (current -> fd == fd)
		{
			if (previous)
				previous -> next = current -> next;
			else
				*head = current -> next;
			if (current -> buffer)
				free(current -> buffer);
			free(current);
			current = NULL;
			return (NULL);
		}
		previous = current;
		current = current -> next;
	}
	return (NULL);
}

static bool	update_buffer(int fd, char buffer[], t_fd_list *node)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read && !ft_strchr(node->buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (false);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(node->buffer, buffer);
		if (!tmp)
			return (false);
		free(node->buffer);
		node->buffer = tmp;
	}
	return (true);
}

static char	*extract_newline(t_fd_list *head, t_fd_list *node)
{
	char	*tmp;
	char	*line;
	char	*endline_pos;

	if (!head || !node || !node->buffer || !*node->buffer)
		return (NULL);
	endline_pos = ft_strchr(node->buffer, '\n');
	if (endline_pos || *node->buffer)
	{
		if (endline_pos)
		{
			line = ft_substr(node->buffer, 0, (endline_pos - node->buffer) + 1);
			tmp = ft_strdup(endline_pos + 1);
		}
		else
		{
			line = ft_strdup(node->buffer);
			tmp = NULL;
		}
		if (!line || (!*line && !*tmp))
			return (free_node(&head, node->fd));
		free(node->buffer);
		node->buffer = tmp;
		return (line);
	}
	return (free_node(&head, node->fd));
}

char	*get_next_line(int fd)
{
	char				*line;
	char				*buffer;
	t_fd_list			*node_fd;
	static t_fd_list	*head = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	node_fd = get_node(&head, fd);
	if (!node_fd)
		return (NULL);
	if (node_fd -> buffer == NULL)
		node_fd -> buffer = ft_strdup("");
	if (!node_fd -> buffer || !update_buffer(fd, buffer, node_fd))
	{
		free(buffer);
		return (free_node(&head, fd));
	}
	line = extract_newline(head, node_fd);
	free(buffer);
	if (line)
		return (line);
	return (free_node(&head, fd));
}
