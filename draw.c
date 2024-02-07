/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:17:50 by tohma             #+#    #+#             */
/*   Updated: 2024/02/06 12:56:29 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	int		pos;
	char	*dest;

	if (x > img->vars->win_width || x < 0 || y > img->vars->win_height || y < 0)
		return ;
	pos = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dest = img->addr + pos;
	*((unsigned int *)dest) = color;
}

void	draw_square(t_img *img, int x, int y, int size)
{
	int				i;
	unsigned int	color;

	i = -1;
	color = 0xFFFFFFFF;
	while (++i < size)
	{
		draw_pixel(img, x + i, y, color);
		draw_pixel(img, x + size, y + i, color);
		draw_pixel(img, x + i, y + size, color);
		draw_pixel(img, x, y + i, color);
	}
	draw_pixel(img, x + size, y + size, color);
}

/* TODO Fixer quand dx = 0 */
void	draw_line(t_img *img, t_vector from, t_vector to)
{
	int		dx;
	int		dy;
	int		x;
	int		y;

	x = from.x - 1;
	dx = to.x - from.x;
	dy = to.y - from.y;
	while (++x < to.x)
	{
		y = from.y + dy * (x - from.x) / dx;
		draw_pixel(img, x, y, 0xFFFFFFFF);
	}
}