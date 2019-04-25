/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:56:44 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/24 20:03:27 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_param(t_param s, int *dx, int *dy, int *error)
{
	*dx = abs(s.x2 - s.x1);
	*dy = abs(s.y2 - s.y1);
	*error = *dx - *dy;
}

static void	get_coords(int x2, int y2, void (*f)(), t_param s)
{
	s.x2 = x2;
	s.y2 = y2;
	(*f)(s);
}

void		place_line(t_param s)
{
	int	dx;
	int	dy;
	int	signx;
	int	signy;
	int error;

	find_param(s, &dx, &dy, &error);
	signx = (s.x1 < s.x2) ? 1 : -1;
	signy = (s.y1 < s.y2) ? 1 : -1;
	while (s.x1 != s.x2 || s.y1 != s.y2)
	{
		if (s.x1 >= 0 && s.x1 <= 1300 && s.y1 >= 0 && s.y1 <= 1300)
			mlx_pixel_put(s.mlx_ptr, s.win_ptr, s.x1, s.y1, (s.color -= s.g));
		s.error = error * 2;
		if (s.error > -dy)
		{
			error -= dy;
			s.x1 += signx;
		}
		if (s.error < dx)
		{
			error += dx;
			s.y1 += signy;
		}
	}
}

void		use_cube(t_param s)
{
	int		i;
	int		j;
	void	(*f)(t_param);

	i = -1;
	f = place_line;
	while (++i < s.area->max_y)
	{
		j = -1;
		while (++j < s.area->max_x)
		{
			s.color = (s.area->max_z > 1) ? s.area->color[i][j] : 0xFFFFFF;
			s.x1 = j * s.area->p_scale + s.move_x;
			s.y1 = i * s.area->p_scale + s.move_y;
			if (j < s.area->max_x - 1)
				get_coords(((j + 1) * s.area->p_scale + s.move_x), s.y1, f, s);
			if (i < s.area->max_y - 1)
				get_coords(s.x1, (i + 1) * s.area->p_scale + s.move_y, f, s);
		}
	}
}

void		make_window(t_cube *area)
{
	t_param s;

	s.area = area;
	((s.mlx_ptr = mlx_init())) ? 0 : ft_exit(area, 4);
	((s.win_ptr = mlx_new_window(s.mlx_ptr, 1300, 1300, "AmazinG"))) ? 0 :
								ft_exit(area, 6);
	s.point = 0;
	s.g = 0;
	s.g_x = 0;
	s.g_y = 0;
	print_legend(s);
	close_prog(34, &s);
	mlx_key_hook(s.win_ptr, close_prog, (void*)&s);
	mlx_hook(s.win_ptr, 2, 0, ft_key_menu, (void*)&s);
	mlx_hook(s.win_ptr, 17, 0, ft_close, (void*)&s);
	mlx_loop(s.mlx_ptr);
}
