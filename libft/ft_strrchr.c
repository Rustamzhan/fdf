/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:53:43 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/11 21:34:37 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int y;

	y = ft_strlen(s);
	while (y >= 0)
	{
		if (s[y] != c)
			y--;
		else
			return ((char *)(s + y));
	}
	return (NULL);
}
