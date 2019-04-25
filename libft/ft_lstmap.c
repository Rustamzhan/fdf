/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 22:00:03 by kreilly           #+#    #+#             */
/*   Updated: 2019/01/29 14:15:50 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_lstdel_content(void *content, size_t size)
{
	size = 0;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*copy;
	t_list	*next_list;
	t_list	*new;

	p = lst;
	if (p && (copy = f(p)))
		copy = ft_lstnew(copy->content, copy->content_size);
	else
		return (NULL);
	p = p->next;
	while (p)
	{
		if (!(next_list = f(p)))
		{
			ft_lstdel(&copy, &ft_lstdel_content);
			return (NULL);
		}
		new = ft_lstnew(next_list->content, next_list->content_size);
		ft_last_list_add(&copy, new);
		p = p->next;
	}
	return (copy);
}
