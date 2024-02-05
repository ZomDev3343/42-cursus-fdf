/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:39:49 by tohma             #+#    #+#             */
/*   Updated: 2024/02/05 15:20:19 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_point(t_vector *point, t_camera *cam)
{
	t_mat	proj_mat;

	proj_mat.x = make_vector(1, 0, 0);
	proj_mat.y = make_vector(0, 1, 0);
	proj_mat.z = make_vector(0, 0, 0);
}
