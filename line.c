/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:34:35 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 18:53:02 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(t_img *img, t_vector *from, t_vector *to)
{
	t_plot_utils	pu;

	pu.dx = to->x - from->x;
	pu.dy = to->y - from->y;
	pu.yi = 1;
	if (pu.dy < 0)
	{
		pu.yi = -1;
		pu.dy *= -1;
	}
	pu.d = (2 * pu.dy) - pu.dx;
	pu.y = from->y;
	pu.x = from->x - 1;
	while (++pu.x < to->x)
	{
		draw_pixel(img, drawinfo(pu.x, pu.y, 0xFFFFFFFF));
		if (pu.d > 0)
		{
			pu.y = pu.y + pu.yi;
			pu.d += (2 * (pu.dy - pu.dx));
		}
		else
			pu.d += 2 * pu.dy;
	}
}

static void	draw_line_high(t_img *img, t_vector *from, t_vector *to)
{
	t_plot_utils	pu;

	pu.dx = to->x - from->x;
	pu.dy = to->y - from->y;
	pu.xi = 1;
	if (pu.dx < 0)
	{
		pu.xi = -1;
		pu.dx *= -1;
	}
	pu.d = (2 * pu.dx) - pu.dy;
	pu.x = from->x;
	pu.y = from->y - 1;
	while (++pu.y < to->y)
	{
		draw_pixel(img, drawinfo(pu.x, pu.y, 0xFFFFFFFF));
		if (pu.d > 0)
		{
			pu.x += pu.xi;
			pu.d += (2 * (pu.dx - pu.dy));
		}
		else
			pu.d += 2 * pu.dx;
	}
}

void	draw_line(t_img *img, t_vector *from, t_vector *to)
{
	if (abs(to->y - from->y) < abs(to->x - from->x))
	{
		if (from->x > to->x)
			draw_line_low(img, to, from);
		else
			draw_line_low(img, from, to);
	}
	else
	{
		if (from->y > to->y)
			draw_line_high(img, to, from);
		else
			draw_line_high(img, from, to);
	}
}
