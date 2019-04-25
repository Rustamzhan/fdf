/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:01:42 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/25 11:27:44 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_y(t_cube *area, int y)
{
	area->max_y = y;
	ft_exit(area, 3);
}

void	set_color(int *arr, int color, int len)
{
	while (len-- > 0)
		*arr++ = color;
}

int		close_prog(int key, t_param *s)
{
	if (key == 53)
	{
		mlx_destroy_window(s->mlx_ptr, s->win_ptr);
		ft_exit(s->area, 0);
	}
	if (key == 34)
	{
		s->angle = 0.523599;
		find_scale(s->area);
		s->flag = 2;
		score_begin_point(s);
		mlx_clear_window(s->mlx_ptr, s->win_ptr);
		print_legend(*s);
		use_cube_iso(key, *s);
	}
	if (key == 35)
	{
		find_scale(s->area);
		s->flag = 1;
		score_begin_point(s);
		mlx_clear_window(s->mlx_ptr, s->win_ptr);
		print_legend(*s);
		use_cube(*s);
	}
	return (0);
}

int		ft_close(t_param *s)
{
	ft_exit(s->area, 0);
	return (0);
}

void	print_legend(t_param s)
{
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1100, 0xFFFFFF, "USE KEYS:");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1130, 0xFFFFFF, "p i -projection");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1150, 0xFFFFFF, "+ - -zoom");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1170, 0xFFFFFF, "g   -gradient");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1190, 0xFFFFFF, "x y -rotation");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1210, 0xFFFFFF,
					"1 2 -change angle");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1230, 0xFFFFFF, "->  -moving");
	mlx_string_put(s.mlx_ptr, s.win_ptr, 50, 1250, 0xFFFFFF, "Esc -close");
}
