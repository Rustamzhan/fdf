/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:05:31 by kreilly           #+#    #+#             */
/*   Updated: 2019/01/15 18:28:21 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int y;

	i = 0;
	y = ft_strlen(s);
	while (i <= y)
	{
		if (s[i] != c)
			i++;
		else
			return ((char *)(s + i));
	}
	return (NULL);
}
