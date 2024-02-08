/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:31:10 by tohma             #+#    #+#             */
/*   Updated: 2024/02/08 12:32:35 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_interact	create_interact(int x, int y, int size_x, int size_y)
{
	t_interact	res;

	res.x = x;
	res.y = y;
	res.size_x = size_x;
	res.size_y = size_y;
	return (res);
}

void	center_pos(t_vars *vars, t_interact *obj)
{
	obj->x = vars->win_width / 2 - obj->size_x / 2;
	obj->y = vars->win_height / 2 - obj->size_y / 2;
}
