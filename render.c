/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:25:12 by tohma             #+#    #+#             */
/*   Updated: 2024/02/27 11:48:01 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	render_lines(t_img *img, t_vars *vars)
{
	int			i;
	t_vector	**neighbors;

	i = -1;
	while (++i < vars->map_size)
	{
		neighbors = get_next_neighbors(vars, i);
		if (!neighbors)
			continue ;
		if (neighbors[0])
			draw_line(img, vars->drawn_points + i, neighbors[0]);
		if (neighbors[1])
			draw_line(img, vars->drawn_points + i, neighbors[1]);
		ft_free(neighbors);
	}
}

static t_vector	projection(t_vars *vars, t_vector *point)
{
	if (!vars->proj_mode)
		return (iso_point(vars->cam, point));
	else
		return (curvlinear_point(point));
}

static t_vector	zoom_point(t_vars *vars, t_vector *point, int i)
{
	t_vector	res;

	res = *point;
	if (!vars->proj_mode)
		res = addvec(*point, newvec(
					vars->cam->zoom * (i % vars->map_width),
					vars->cam->zoom * (i / vars->map_width),
					0
					));
	return (res);
}

static void	project_points(t_vars *vars)
{
	int			i;
	t_vector	point;

	i = -1;
	while (++i < vars->map_size)
	{
		point = vars->points[i];
		point.z *= vars->height_mult;
		point = zoom_point(vars, &point, i);
		point = projection(vars, &point);
		point = addvec(point, newvec(
					-vars->cam->x - ((vars->map_width + vars->map_height) / 6
						* (25 + vars->cam->zoom)),
					-vars->cam->y,
					0
					));
		point = project_point(&point);
		point.z = vars->points[i].z * vars->height_mult;
		vars->drawn_points[i] = point;
	}
}

/*
	Renders every frame of the program
*/
int	render_frame(t_vars *vars)
{
	t_img	img;

	img.vars = vars;
	img.img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	img.addr = mlx_get_data_addr(img.img,
			&(img.bits_per_pixel), &(img.line_length),
			&(img.endian));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	project_points(vars);
	render_lines(&img, vars);
	mlx_destroy_image(vars->mlx, img.img);
	return (0);
}
