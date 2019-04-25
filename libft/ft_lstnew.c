/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:55:49 by kreilly           #+#    #+#             */
/*   Updated: 2019/01/29 14:01:20 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(p->content = (char *)malloc(sizeof(char) * content_size)))
		{
			free(p);
			return (NULL);
		}
		else
		{
			ft_memcpy(p->content, content, content_size);
			p->content_size = content_size;
		}
	}
	else
	{
		p->content = NULL;
		p->content_size = 0;
	}
	p->next = NULL;
	return (p);
}
