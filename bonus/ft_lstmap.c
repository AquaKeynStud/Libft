/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:18:12 by arocca            #+#    #+#             */
/*   Updated: 2024/11/19 15:44:30 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*nlist;
	void	*new_cnt;

	nlist = NULL;
	new_node = NULL;
	while (lst)
	{
		new_cnt = f(lst -> content);
		if (!new_cnt)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_cnt);
		if (!new_node)
		{
			del(new_cnt);
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, new_node);
		lst = lst -> next;
	}
	return (nlist);
}
