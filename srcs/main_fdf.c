/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:41:42 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/25 12:18:00 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_struct(t_cube *area)
{
	int j;
	int x;

	j = 0;
	x = 0;
	if (area->cube)
	{
		if (area->max_x > 0 || area->max_y > 0)
		{
			while (x < area->max_z)
			{
				while (j < area->max_y)
					free(area->cube[x][j++]);
				j = 0;
				free(area->cube[x]);
				x++;
			}
		}
		free(area->cube);
	}
	free(area);
}

void			ft_exit(t_cube *area, int x)
{
	if (area)
		free_struct(area);
	if (x == 0)
		exit(0);
	if (x == 1)
		ft_putstr_fd("usage: fdf [file]\n", 2);
	else if (x == 2)
		ft_putstr_fd("Problems with file\n", 2);
	else if (x == 3)
		ft_putstr_fd("Wrong map\n", 2);
	else if (x == 4)
		ft_putstr_fd("Lost connection with server\n", 2);
	else if (x == 5)
		ft_putstr_fd("Impossible to work with file\n", 2);
	else if (x == 6)
		ft_putstr_fd("Impossible to open window\n", 2);
	else if (x == 8)
		ft_putstr_fd("No available memory\n", 2);
	exit(1);
}

static int		read_map(char *argv, int *y, int *z)
{
	int		i;
	int		fd;
	int		res;
	char	buff[1001];

	if ((fd = open(argv, O_RDONLY)) < 0 || (read(fd, buff, 0) < 0))
		return (-1);
	while ((res = read(fd, buff, 1000)) > 0)
	{
		i = 0;
		buff[res] = '\0';
		while (buff[i])
		{
			if (*z == 1)
				if (buff[i] == '0' && buff[i + 1] == 'x')
					*z = 2;
			if (buff[i] == '\n')
				(*y)++;
			i++;
		}
	}
	return ((close(fd) < 0) ? -1 : 0);
}

static t_cube	*main_cube(char *argv)
{
	t_cube	*area;

	if (!(area = (t_cube *)malloc(sizeof(t_cube) * 1)))
		ft_exit(0, 8);
	area->max_x = 0;
	area->max_y = 0;
	area->max_z = 1;
	area->cube = NULL;
	if (read_map(argv, &area->max_y, &area->max_z) < 0)
		ft_exit(area, 2);
	make_cube(argv, area);
	if (area->max_x < 2 && area->max_y < 2)
		ft_exit(area, 3);
	area->count = 0;
	area->alt = (area->cube)[0];
	area->color = (area->cube)[1];
	find_alt(area);
	return (area);
}

int				main(int argc, char **argv)
{
	t_cube *area;

	if (argc != 2)
		ft_exit(0, 1);
	area = main_cube(argv[1]);
	make_window(area);
	return (0);
}
