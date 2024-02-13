/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:12:22 by tohma             #+#    #+#             */
/*   Updated: 2024/02/13 13:39:13 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_cam(t_cam *cam)
{
	if (!cam)
		return ;
	cam->angle = 90.0;
	cam->near = 10.0;
	cam->far = 1000.0;
	cam->fov = 90.0;
	cam->x = 0;
	cam->y = 0;
}

void	setup_vars(t_vars **vars)
{
	*vars = (t_vars *) ft_calloc(1, sizeof(t_vars));
	if (!*vars)
		return ;
	(*vars)->cam = (t_cam *) ft_calloc(1, sizeof(t_cam));
	if (!(*vars)->cam)
		return (free(*vars));
	setup_cam((*vars)->cam);
}
