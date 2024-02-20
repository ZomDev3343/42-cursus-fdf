/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:53:51 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 15:24:06 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	**get_next_neighbors(t_vars *vars, int point_idx)
{
	t_vector	**neighbors;

	neighbors = (t_vector **) ft_calloc(2, sizeof(t_vector *));
	if (!neighbors)
		return (NULL);
	if (point_idx % vars->map_width < vars->map_width - 1)
		neighbors[0] = vars->points + point_idx + 1;
	if (point_idx + vars->map_width < vars->map_size)
		neighbors[1] = vars->points + point_idx + vars->map_width;
	return (neighbors);
}
