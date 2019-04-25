/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:33:24 by kreilly           #+#    #+#             */
/*   Updated: 2018/12/10 20:10:09 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	int					sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v' ||
		str[i] == ' ' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		num = str[i++] - '0' + num * 10;
	if (num > 9223372036854775807)
		return (sign < 0 ? 0 : (-1));
	return (num * sign);
}
