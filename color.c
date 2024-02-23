/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:09:23 by tohma             #+#    #+#             */
/*   Updated: 2024/02/23 13:29:38 by tohma            ###   ########.fr       */
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

int	point_color(int dz, int z, t_vars *vars)
{
	double	ratio;

	if (z == 0)
		return (WHITE);
	if (z > 0)
		return (ratio = ((double) z) / vars->top, HIGH_COLOR * ratio);
	else
		return (ratio = ((double) z) / vars->bottom, LOW_COLOR * ratio);
}

int	test_color(double ratio)
{
	return (HIGH_COLOR * ratio);
}
