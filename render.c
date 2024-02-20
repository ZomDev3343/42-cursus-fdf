/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:25:12 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 22:10:20 by tohma            ###   ########.fr       */
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
			draw_line(img, vars->points + i, neighbors[0]);
		if (neighbors[1])
			draw_line(img, vars->points + i, neighbors[1]);
		ft_free(neighbors);
	}
}

static void	render_points(t_img *img, t_vars *vars)
{
	int			i;
	t_vector	point;

	i = -1;
	while (++i < vars->map_size)
	{
		point = vars->points[i];
		point = iso_point(vars->cam, vars->points + i);
		point = addvec(point, newvec(300, 200, 0));
		point = project_point(vars->cam, &point);
		draw_pixel(img, drawinfo(point.x, point.y, 0xFFFFFFFF));
	}
}

/*
	Renders every frame of the program
*/
int	render_frame(t_vars *vars)
{
	t_img	img;

	img.vars = vars;
	img.img = mlx_new_image(vars->mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img,
			&(img.bits_per_pixel), &(img.line_length),
			&(img.endian));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	//render_lines(&img, vars);
	render_points(&img, vars);
	mlx_destroy_image(vars->mlx, img.img);
	vars->cam->angle += 0.1;
	if (vars->cam->angle >= 360.0)
		vars->cam->angle = 0.0;
	printf("Cam angle: %f\n", vars->cam->angle);
	return (0);
}
