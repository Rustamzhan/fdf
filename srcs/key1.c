/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:55:05 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/24 17:01:06 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		score_begin_point(t_param *s)
{
	int	sc;
	int	sp;

	sp = s->area->p_scale;
	sc = s->area->i_scale;
	s->move_x_iso = (1300 - (s->area->max_x - s->area->max_y) * sc) / 2;
	s->move_y_iso = (1300 + (s->area->max_alt - s->area->max_y) * sc) / 2;
	s->move_x = (1300 - s->area->max_x * sp) / 2;
	s->move_y = (1300 - s->area->max_y * sp) / 2;
}

void		find_scale(t_cube *area)
{
	int square;

	square = sqrt(area->max_x * area->max_x + area->max_y * area->max_y);
	area->p_scale = 1300.0 / square;
	area->i_scale = 1000.0 / (area->max_alt - area->min_alt + square);
}

static void	ft_zoom_iso(int key, t_param *s)
{
	if (key == 69 || key == 24)
		s->area->i_scale += (s->area->i_scale < 100) ? 1 : 0;
	if (key == 27 || key == 78)
		s->area->i_scale -= (s->area->i_scale > 1) ? 1 : 0;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	if (s->flag == 2)
		use_cube_iso(key, *s);
	if (s->flag == 3)
		use_cube_iso(7, *s);
	if (s->flag == 4)
		use_cube_iso(16, *s);
}

static void	ft_zoom_par(int key, t_param *s)
{
	if (key == 69 || key == 24)
		s->area->p_scale += (s->area->p_scale < 100) ? 1 : 0;
	if (key == 27 || key == 78)
		s->area->p_scale -= (s->area->p_scale > 1) ? 1 : 0;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	print_legend(*s);
	use_cube(*s);
}

int			ft_key_menu(int key, t_param *s)
{
	if (key == 123 || key == 124)
		move_x(key, s);
	if (key == 126 || key == 125)
		move_y(key, s);
	if (key == 16 || key == 7)
		change_flag(key, s);
	if ((key == 18 || key == 19) && (s->flag == 3 || s->flag == 4))
		rotate(key, s);
	if (key == 5)
		gradient(key, s);
	if (s->flag == 2 || s->flag == 3 || s->flag == 4)
		ft_zoom_iso(key, s);
	if (s->flag == 1)
		ft_zoom_par(key, s);
	return (0);
}
