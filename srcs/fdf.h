/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:12:30 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/25 12:18:28 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# define ERROR (s[i] != '\n' && s[i] != '\0')

typedef struct	s_cube
{
	int	max_x;
	int	max_y;
	int	max_z;
	int max_alt;
	int min_alt;
	int	scale;
	int	count;
	int	p_scale;
	int	i_scale;
	int	***cube;
	int	**alt;
	int	**color;
}				t_cube;

typedef struct	s_param
{
	float	angle;
	float	rotate_x;
	float	rotate_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z;
	int		color;
	int		point;
	int		error;
	int		move_x;
	int		move_y;
	int		move_x_iso;
	int		move_y_iso;
	int		flag;
	int		g;
	int		g_x;
	int		g_y;
	t_cube	*area;
	char	*begin;
}				t_param;

void			print_legend(t_param s);
void			change_flag(int key, t_param *s);
void			set_color(int *arr, int color, int len);
void			gradient(int key, t_param *s);
void			find_alt(t_cube *area);
void			place_line(t_param s);
void			find_scale(t_cube *area);
void			use_cube(t_param s);
void			use_cube_iso(int key, t_param s);
void			make_window(t_cube *area);
void			make_cube(char *name, t_cube *area);
void			ft_exit(t_cube *area, int x);
void			free_mas(int ***arr, int y, int z);
void			score_begin_point(t_param *s);
void			move_x(int key, t_param *s);
void			move_y(int key, t_param *s);
void			rotate(int key, t_param *s);
void			set_y(t_cube *area, int y);
int				close_prog(int key, t_param *s);
int				ft_close(t_param *param);
int				ft_key_menu(int key, t_param *s);

#endif
