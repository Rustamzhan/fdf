/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:57:28 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/25 12:17:50 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			find_alt(t_cube *area)
{
	int x;
	int y;

	x = -1;
	y = -1;
	area->min_alt = (area->alt)[0][0];
	area->max_alt = (area->alt)[0][0];
	while (++y < area->max_y)
	{
		while (++x < area->max_x)
		{
			if (area->min_alt > (area->alt)[y][x])
				area->min_alt = (area->alt)[y][x];
			if (area->max_alt < (area->alt)[y][x])
				area->max_alt = (area->alt)[y][x];
		}
		x = -1;
	}
}

static int		find_hex(char *str)
{
	int n;
	int i;
	int power;
	int num;

	power = 5;
	n = 0;
	if (!(str[0]) || !(str[1]) || str[0] != '0' || str[1] != 'x')
		return (-1);
	i = 2;
	while (str[i] && str[i] != ' ' && i < 8)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = str[i] - 'a' + 10;
		else
			return (-1);
		n = n + num * pow(16, power--);
		i++;
	}
	return ((str[i] != ' ' && str[i] != '\n' && str[i] != '\0') ? -1 : n);
}

static int		find_x(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (*str == ' ')
		str++;
	while (str[i])
	{
		j++;
		i++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return ((j < 1) ? -1 : j);
}

static int		fill_x(int ***ar, char *s, int y, t_cube *area)
{
	int x;
	int i;

	i = 0;
	x = -1;
	while (*s == ' ')
		s++;
	while (s[i] && ++x < area->max_x)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
			ar[0][y][x] = ft_atoi(&s[i]);
		else
			return (-1);
		while (s[i] && s[i] != ' ')
		{
			if (area->max_z > 1)
				if (s[i] == ',')
					if ((ar[1][y][x] = find_hex(&s[i + 1])) < 0)
						return (-1);
			i++;
		}
		while (s[i] == ' ')
			i++;
	}
	return ((ERROR || x != (area->max_x - 1) ? -1 : 0));
}

void			make_cube(char *name, t_cube *area)
{
	int		i;
	int		fd;
	char	*str;

	i = area->max_z;
	area->cube = (int***)malloc(sizeof(int *) * i);
	while (i > 0)
		area->cube[--i] = (int**)malloc(sizeof(int *) * area->max_y);
	(fd = open(name, O_RDONLY)) < 0 ? ft_exit(area, 2) : 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (i == 0)
			((area->max_x = find_x(str)) < 0) ? set_y(area, i) : 0;
		area->cube[0][i] = (int *)malloc(sizeof(int) * (area->max_x));
		if (area->max_z > 1)
		{
			area->cube[1][i] = (int *)malloc(sizeof(int) * (area->max_x));
			set_color(area->cube[1][i], 16777215, area->max_x);
		}
		(fill_x(area->cube, str, i, area) < 0) ? set_y(area, i) : 0;
		i++;
		ft_strdel(&str);
	}
	close(fd);
}
