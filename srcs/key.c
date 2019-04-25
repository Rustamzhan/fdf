/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:54:19 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/24 16:54:43 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(int key, t_param *s)
{
	if (key == 124)
	{
		s->move_x += 10;
		s->move_x_iso += 10;
	}
	if (key == 123)
	{
		s->move_x -= 10;
		s->move_x_iso -= 10;
	}
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	if (s->flag == 1)
		use_cube(*s);
	if (s->flag == 2)
		use_cube_iso(key, *s);
	if (s->flag == 3)
		use_cube_iso(7, *s);
	if (s->flag == 4)
		use_cube_iso(16, *s);
}

void	move_y(int key, t_param *s)
{
	if (key == 125)
	{
		s->move_y += 10;
		s->move_y_iso += 10;
	}
	if (key == 126)
	{
		s->move_y -= 10;
		s->move_y_iso -= 10;
	}
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	if (s->flag == 1)
		use_cube(*s);
	if (s->flag == 2)
		use_cube_iso(key, *s);
	if (s->flag == 3)
		use_cube_iso(7, *s);
	if (s->flag == 4)
		use_cube_iso(16, *s);
}

void	change_flag(int key, t_param *s)
{
	if (key == 16)
	{
		s->flag = 3;
		s->angle = 1;
	}
	if (key == 7)
	{
		s->flag = 4;
		s->angle = -1;
	}
}

void	rotate(int key, t_param *s)
{
	if (key == 18)
		s->angle -= 0.02;
	if (key == 19)
		s->angle += 0.02;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	if (s->flag == 3)
		use_cube_iso(7, *s);
	if (s->flag == 4)
		use_cube_iso(16, *s);
}

void	gradient(int key, t_param *s)
{
	s->g = (s->g) ? 0 : 80;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	(s->flag == 1) ? use_cube(*s) : 0;
	(s->flag == 2) ? use_cube_iso(key, *s) : 0;
	(s->flag == 3) ? use_cube_iso(7, *s) : 0;
	(s->flag == 4) ? use_cube_iso(16, *s) : 0;
}
