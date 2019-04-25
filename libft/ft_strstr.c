/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:18:43 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/29 19:40:12 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] != needle[j])
			i++;
		while (haystack[i] && (haystack[i] == needle[j]))
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char*)(haystack + i - j));
		}
		if (haystack[i])
			i = i - (j - 1);
		j = 0;
	}
	return (NULL);
}
