/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:35:59 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/19 22:22:13 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int i;

	i = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		a;
	int		sign;

	sign = 1;
	a = count(n);
	p = (char *)malloc(sizeof(char) * (a + 1));
	if (p == NULL)
		return (NULL);
	p[a--] = '\0';
	if (n < 0)
		sign = -1;
	while ((sign == 1 && a >= 0) || (sign == -1 && a > 0))
	{
		p[a] = n % 10 * sign + 48;
		n = n / 10;
		a--;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}
