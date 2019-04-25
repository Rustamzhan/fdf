/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:36:13 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/28 18:47:33 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	if (!(alst) || !(*alst) || !(del))
		return ;
	p = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = p;
}
