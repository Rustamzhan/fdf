/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:36:55 by kreilly           #+#    #+#             */
/*   Updated: 2019/01/21 17:20:31 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len > 0)
	{
		if (*src)
		{
			dst[i] = *src;
			src++;
		}
		else
			dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
