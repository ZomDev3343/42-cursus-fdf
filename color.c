/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:09:23 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 17:48:44 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_top_bottom(t_vars *vars)
{
	int		i;
	double	highest;
	double	lowest;

	i = -1;
	highest = vars->points[0].z;
	lowest = vars->points[0].z;
	while (++i < vars->map_size)
	{
		if (vars->drawn_points[i].z > highest)
			highest = vars->drawn_points[i].z;
		else if (vars->drawn_points[i].z < lowest)
			lowest = vars->drawn_points[i].z;
	}
	vars->bottom = lowest;
	vars->top = highest;
}

int	point_color(double height, t_vars *vars)
{
	int		color;
	double	ratio;

	if (height > 0)
	{
		ratio = height / vars->top;
		color = HIGH_COLOR * ratio;
		return (color);
	}
	ratio = height / vars->bottom;
	color = LOW_COLOR * ratio;
	return (color);
}

int	test_color(double ratio)
{
	return (HIGH_COLOR * ratio);
}
