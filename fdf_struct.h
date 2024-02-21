/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:36:14 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 12:03:08 by tohma            ###   ########.fr       */
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
	double	near;
	double	far;
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
	int	dx;
	int	dy;
	int	yi;
	int	xi;
	int	d;
	int	x;
	int	y;
}	t_plot_utils;

#endif