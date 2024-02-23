/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:25:12 by tohma             #+#    #+#             */
/*   Updated: 2024/02/23 14:57:10 by tohma            ###   ########.fr       */
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

static void	project_points(t_img *img, t_vars *vars)
{
	int			i;
	t_vector	point;

	i = -1;
	while (++i < vars->map_size)
	{
		point = vars->points[i];
		point.z *= vars->height_mult;
		point = addvec(point, newvec(
					vars->cam->zoom * (i % vars->map_width),
					vars->cam->zoom * (i / vars->map_width),
					0
					));
		point = iso_point(vars->cam, &point);
		point = addvec(point, newvec(
					-vars->cam->x - ((vars->map_width + vars->map_height) / 3
						* (25 + vars->cam->zoom)),
					-vars->cam->y,
					0
					));
		point = project_point(&point);
		point.z = vars->points[i].z;
		vars->drawn_points[i] = point;
	}
	set_top_bottom(vars);
}

static void	render_points(t_img *img, t_vars *vars)
{
	int			i;
	t_vector	*point;

	i = -1;
	while (++i < vars->map_size)
	{
		point = vars->drawn_points + i;
		draw_pixel(img, drawinfo(point->x, point->y,
				point_color(0, point->z, vars)));
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
	project_points(&img, vars);
	render_lines(&img, vars);
	render_points(&img, vars);
	mlx_destroy_image(vars->mlx, img.img);
	return (0);
}
