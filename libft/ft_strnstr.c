/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:23:42 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/29 20:12:21 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	t_strncmp(char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (!*s2)
		return (0);
	else if (*s1 - *s2 != 0)
		return (*s1 - *s2);
	else if (*s1 - *s2 == 0)
	{
		if (*(s2 + 1) == '\0')
			return (0);
		else
			return (-5);
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	char	*h;

	c = 1;
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack && c <= len)
	{
		if (*haystack == *needle)
		{
			h = (char*)haystack;
			if (t_strncmp(h, needle, (len - c)) == 0)
				return ((char*)haystack);
			c++;
			haystack++;
		}
		c++;
		if (*haystack)
			haystack++;
	}
	return (NULL);
}
