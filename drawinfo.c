/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:53:33 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 17:30:13 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Creates a struct for drawing purpose
*/
t_draw_info	drawinfo(int start_x, int start_y, int color)
{
	t_draw_info	info;

	info.start_x = start_x;
	info.start_y = start_y;
	info.color = color;
	return (info);
}

/*
	Offsets an existing drawinfo variable
*/
t_draw_info	add_xy_info(t_draw_info *info, int add_x, int add_y)
{
	t_draw_info	res;

	res.start_x = info->start_x + add_x;
	res.start_y += info->start_y + add_y;
	res.color = info->color;
	return (res);
}
