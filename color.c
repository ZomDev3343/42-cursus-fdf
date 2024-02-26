/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:09:23 by tohma             #+#    #+#             */
/*   Updated: 2024/02/26 15:47:14 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	get_hexcolor(unsigned int hex)
{
	t_color	color;

	color.a = hex >> 24 & 0xFF;
	color.r = hex >> 16 & 0xFF;
	color.g = hex >> 8 & 0xFF;
	color.b = hex & 0xFF;
	return (color);
}

static int	fade_color(t_color start, t_color end, double dist)
{
	t_color	res;

	res = end;
	if (dist <= 0.5)
	{
		dist *= 2.0;
		res.r = start.r * (1.0 - dist) + 0.5;
		res.g = start.g * dist + 0.5;
	}
	else
	{
		dist = dist * 2.0 - 1.0;
		res.g = start.g * (1.0 - dist) + 0.5;
		res.b = start.b * dist + 0.5;
	}
	return (res.a << 24 | res.r << 16 | res.g << 8 | res.b);
}

void	set_top_bottom(t_vars *vars)
{
	int		i;
	double	highest;
	double	lowest;

	i = -1;
	highest = 1.0;
	lowest = -1.0;
	while (++i < vars->map_size)
	{
		if (vars->points[i].z > highest)
			highest = vars->points[i].z;
		else if (vars->points[i].z < lowest)
			lowest = vars->points[i].z;
	}
	vars->bottom = lowest * vars->height_mult;
	vars->top = highest * vars->height_mult;
}

int	point_color(int z, t_vars *vars)
{
	double	ratio;
	double	t;

	t = z;
	if (z == 0)
		return (WHITE);
	if (z > 0)
		return (ratio = t / vars->top,
			fade_color(get_hexcolor(WHITE), get_hexcolor(HIGH_COLOR), ratio));
	else
		return (ratio = t / vars->bottom,
			fade_color(get_hexcolor(WHITE), get_hexcolor(LOW_COLOR), ratio));
}
