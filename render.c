/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:25:12 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 17:09:52 by tohma            ###   ########.fr       */
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
		point = iso_point(vars->cam, vars->points + i);
		vars->drawn_points[i] = addvec(point, newvec(
					vars->cam->zoom * i + (vars->map_width / 2 * 40),
					vars->cam->zoom * (i / vars->map_width)
					+ (vars->map_height / 2 * 60),
					0));
	}
	set_top_bottom(vars);
}

/*
	Renders every frame of the program
*/
int	render_frame(t_vars *vars)
{
	t_img	img;

	img.vars = vars;
	mlx_get_screen_size(vars->mlx, &(vars->win_width), &(vars->win_height));
	img.img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	img.addr = mlx_get_data_addr(img.img,
			&(img.bits_per_pixel), &(img.line_length),
			&(img.endian));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	project_points(&img, vars);
	render_lines(&img, vars);
	mlx_destroy_image(vars->mlx, img.img);
	vars->cam->angle += 0.1;
	if (vars->cam->angle >= 360.0)
		vars->cam->angle = 0.0;
	return (0);
}
