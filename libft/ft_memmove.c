/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:43:12 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/20 22:24:49 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if ((src - dst) > 0)
	{
		while (len > i)
		{
			((char *)dst)[i] = ((char *)src)[j];
			i++;
			j++;
		}
	}
	else if ((src - dst) < 0)
	{
		while (len)
		{
			((char *)dst)[i + len - 1] = ((char *)src)[j + len - 1];
			len--;
		}
	}
	return ((char*)dst);
}
