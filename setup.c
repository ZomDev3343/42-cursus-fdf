/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:12:22 by tohma             #+#    #+#             */
/*   Updated: 2024/02/23 14:51:37 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_cam(t_cam *cam, t_vars *vars)
{
	if (!cam)
		return ;
	cam->angle = 45.0;
	cam->zoom = 0.0;
	cam->fov = 90.0;
	cam->x = -vars->win_width / 2;
	cam->y = -vars->win_height / 2;
}

void	setup_vars(t_vars **vars)
{
	*vars = (t_vars *) ft_calloc(1, sizeof(t_vars));
	if (!*vars)
		return ;
	(*vars)->win_width = 800;
	(*vars)->win_height = 600;
	(*vars)->height_mult = 1.0;
	(*vars)->cam = (t_cam *) ft_calloc(1, sizeof(t_cam));
	if (!(*vars)->cam)
		return (free(*vars));
	setup_cam((*vars)->cam, *vars);
}
