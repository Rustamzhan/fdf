/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:12:26 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/20 19:22:15 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i])
		i++;
	while ((s[i] == '\0' || s[i] == ' ' || s[i] == '\n' ||
			s[i] == '\t') && i >= 0)
		i--;
	p = (char *)malloc(sizeof(char) * (&s[i] - s + 2));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s, (&s[i] - s + 1));
	p[i + 1] = '\0';
	return (p);
}
