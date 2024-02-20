/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:25:12 by tohma             #+#    #+#             */
/*   Updated: 2024/02/19 16:46:02 by tohma            ###   ########.fr       */
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
		if (neighbors[0])
			draw_line(img, vars->points[i], *(neighbors[0]));
		if (neighbors[1])
			draw_line(img, vars->points[i], *(neighbors[1]));
		ft_free(neighbors);
	}
}

static void	render_points(t_img *img, t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->map_size)
		draw_pixel(img, drawinfo(vars->points[i].x,
				vars->points[i].y, 0xFABF));
}

int	render_frame(t_vars *vars)
{
	t_img	img;

	img.vars = vars;
	img.img = mlx_new_image(vars->mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img,
			&(img.bits_per_pixel), &(img.line_length),
			&(img.endian));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
	render_lines(&img, vars);
	render_points(&img, vars);
	mlx_destroy_image(vars->mlx, img.img);
	return (0);
}
