/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:34:58 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/29 20:42:41 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_find_len(char const *s, char c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (*s == c)
		s++;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static	char	*new_string(char const *s, char c)
{
	char	*a;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (s[n] && s[n] != c)
		n++;
	a = (char*)malloc(sizeof(char) * (n + 1));
	if (a == NULL)
		return (NULL);
	while (i < n)
		a[i++] = *s++;
	a[i] = '\0';
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mas;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_find_len(s, c);
	mas = (char**)malloc(sizeof(char*) * (len + 1));
	if (mas == NULL)
		return (NULL);
	mas[len] = NULL;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		mas[i] = new_string(s, c);
		i++;
		while (*s && *s != c)
			s++;
	}
	return (mas);
}
