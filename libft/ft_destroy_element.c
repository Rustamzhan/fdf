/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destoy_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:03:48 by kreilly           #+#    #+#             */
/*   Updated: 2019/02/13 16:12:09 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destroy_element(t_list **lst, t_list **elem)
{
	t_list *temp_p_fd;
	t_list *temp_root;

	if (!lst || !*elem)
		return ;
	temp_root = *lst;
	temp_p_fd = *elem;
	if (temp_root != temp_p_fd)
	{
		while (temp_root->next != temp_p_fd)
			temp_root = temp_root->next;
		temp_root->next = temp_p_fd->next;
	}
	else
	{
		temp_root = temp_p_fd->next;
		*lst = temp_root;
	}
	free(*elem);
	*elem = NULL;
}
