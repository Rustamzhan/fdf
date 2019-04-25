/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:51:13 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/25 12:17:28 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	save_coord_rot_x(t_param *s, int i, int j)
{
	s->x1 = j * s->area->i_scale + s->move_x_iso;
	s->y1 = (i * cos(s->angle) + s->area->alt[i][j] * sin(s->angle)) *
			s->area->i_scale + s->move_y_iso;
	if (j < s->area->max_x - 1)
	{
		s->x2 = (j + 1) * s->area->i_scale + s->move_x_iso;
		s->y2 = (i * cos(s->angle) + s->area->alt[i][j + 1] *
				sin(s->angle)) * s->area->i_scale + s->move_y_iso;
		place_line(*s);
	}
	if (i < s->area->max_y - 1)
	{
		s->x2 = s->x1;
		s->y2 = ((i + 1) * cos(s->angle) + s->area->alt[i + 1][j] *
				sin(s->angle)) * s->area->i_scale + s->move_y_iso;
		place_line(*s);
	}
}

static void	save_coord_rot_y(t_param *s, int i, int j)
{
	s->x1 = (j * cos(s->angle) + s->area->alt[i][j] * sin(s->angle)) *
			s->area->i_scale + s->move_x_iso;
	s->y1 = i * s->area->i_scale + s->move_y_iso;
	if (j < s->area->max_x - 1)
	{
		s->x2 = ((j + 1) * cos(s->angle) + s->area->alt[i][j + 1] *
				sin(s->angle)) * s->area->i_scale + s->move_x_iso;
		s->y2 = s->y1;
		place_line(*s);
	}
	if (i < s->area->max_y - 1)
	{
		s->x2 = (j * cos(s->angle) + s->area->alt[i + 1][j] *
				sin(s->angle)) * s->area->i_scale + s->move_x_iso;
		s->y2 = (i + 1) * s->area->i_scale + s->move_y_iso;
		place_line(*s);
	}
}

static void	save_coord(t_param *s, int i, int j)
{
	s->x1 = (j - i) * cos(s->angle) * s->area->i_scale + s->move_x_iso;
	s->y1 = (((i + j) * sin(s->angle)) - s->area->alt[i][j]) *
			s->area->i_scale + s->move_y_iso;
	if (j < s->area->max_x - 1)
	{
		s->x2 = (j + 1 - i) * cos(s->angle) * s->area->i_scale + s->move_x_iso;
		s->y2 = (((i + j + 1) * sin(s->angle)) - s->area->alt[i][j + 1]) *
				s->area->i_scale + s->move_y_iso;
		place_line(*s);
	}
	if (i < s->area->max_y - 1)
	{
		s->x2 = (j - 1 - i) * cos(s->angle) * s->area->i_scale + s->move_x_iso;
		s->y2 = ((i + 1 + j) * sin(s->angle) - s->area->alt[i + 1][j]) *
				s->area->i_scale + s->move_y_iso;
		place_line(*s);
	}
}

void		use_cube_iso(int key, t_param s)
{
	int	i;
	int	j;

	s.x1 = 0;
	s.y1 = 0;
	i = -1;
	while (++i < s.area->max_y)
	{
		j = -1;
		while (++j < s.area->max_x)
		{
			s.color = (s.area->max_z > 1) ? s.area->color[i][j] : 0xFFFFFF;
			(key != 16 && key != 7) ? save_coord(&s, i, j) : 0;
			(key == 16) ? save_coord_rot_y(&s, i, j) : 0;
			(key == 7) ? save_coord_rot_x(&s, i, j) : 0;
		}
	}
}
