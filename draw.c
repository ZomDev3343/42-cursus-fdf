/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:37:45 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 17:30:08 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Draws a pixel
*/
void	draw_pixel(t_img *img, t_draw_info info)
{
	int		pos;
	char	*dest;

	if (info.start_x > img->vars->win_width || info.start_x < 0
		|| info.start_y > img->vars->win_height || info.start_y < 0)
		return ;
	pos = (info.start_y * img->line_length
			+ info.start_x * (img->bits_per_pixel / 8));
	dest = img->addr + pos;
	*((unsigned int *)dest) = info.color;
}

/*
	Draws empty square
*/
void	draw_square(t_img *img, t_draw_info info, int size)
{
	int				i;

	i = -1;
	while (++i < size)
	{
		draw_pixel(img, add_xy_info(&info, i, 0));
		draw_pixel(img, add_xy_info(&info, size, i));
		draw_pixel(img, add_xy_info(&info, i, size));
		draw_pixel(img, add_xy_info(&info, 0, i));
	}
	draw_pixel(img, add_xy_info(&info, size, size));
}

/*
	Draws a filled square of a specified size
*/
//TODO
void	draw_fsquare(t_img *img, t_draw_info info, int size)
{
	int				i;

	i = -1;
	while (++i < size)
	{
		draw_pixel(img, add_xy_info(&info, i, 0));
		draw_pixel(img, add_xy_info(&info, size, i));
		draw_pixel(img, add_xy_info(&info, i, size));
		draw_pixel(img, add_xy_info(&info, 0, i));
	}
	draw_pixel(img, add_xy_info(&info, size, size));
}
