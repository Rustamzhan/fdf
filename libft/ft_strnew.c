/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:33:39 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/30 00:19:20 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	if (size == (size_t)(-1))
		return (NULL);
	p = (char*)(malloc(size + 1));
	if (!p)
		return (NULL);
	ft_bzero(p, size + 1);
	return (p);
}
