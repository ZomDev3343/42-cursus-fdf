/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:36:14 by tohma             #+#    #+#             */
/*   Updated: 2024/02/26 15:20:56 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_mat
{
	t_vector	c1;
	t_vector	c2;
	t_vector	c3;
}	t_mat;

typedef struct s_cam
{
	double	angle;
	double	zoom;
	double	fov;
	int		x;
	int		y;
}	t_cam;

typedef struct s_vars
{
	int			map_width;
	int			map_height;
	int			map_size;
	int			win_width;
	int			win_height;
	t_cam		*cam;
	t_vector	*points;
	t_vector	*drawn_points;
	double		top;
	double		bottom;
	double		height_mult;
	int			proj_mode;
	void		*mlx;
	void		*mlx_win;
}	t_vars;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_vars		*vars;
}	t_img;

typedef struct s_draw_info
{
	int	start_x;
	int	start_y;
	int	color;
}	t_draw_info;

typedef struct s_plot_utils
{
	int		dx;
	int		dy;
	int		dz;
	int		xi;
	int		yi;
	int		zi;
	int		d;
	int		x;
	int		y;
	double	z;
}	t_plot_utils;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

#endif