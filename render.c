/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:22:02 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 11:22:07 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void render_map(t_img *img)
{
    t_map *map;
    int   padding;
    int   i;

    padding = 20;
    i = -1;
    map = img->vars->map;
    while (++i < map->width * map->height)
        draw_pixel(img, 100 + padding * (i % map->width),
          100 + padding * (i / map->width), 0xFFFFFFFF);
}

static void render_fdf(t_img *img)
{
    render_map(img);
}

int render_frame(t_vars *vars)
{
    t_img   img;

    img.vars = vars;
    img.img = mlx_new_image(vars->mlx, 800, 600);
		img.addr = mlx_get_data_addr(img.img,
			&(img.bits_per_pixel), &(img.line_length),
				&(img.endian));
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
    render_fdf(&img);
    mlx_do_sync(vars->mlx);
    mlx_destroy_image(vars->mlx, img.img);
    return (0);
}