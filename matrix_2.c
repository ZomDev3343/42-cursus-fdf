/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:35:34 by tohma             #+#    #+#             */
/*   Updated: 2024/02/08 16:01:54 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	project_point(t_camera *cam, t_vector *point)
{
	t_mat		proj_mat;
	t_vector	proj_point;

	proj_mat = make_matrix3(make_vector(1 + cos(point->z), 0, 0),
			make_vector(0, 1 + sin(point->z), 0),
			make_vector(0, 0, 0));
	proj_point = matvec(&proj_mat, point);
	return (proj_point);
}

t_vector	rotate_point_x(t_camera *cam, t_vector *point)
{
	t_mat		rot_mat;
	t_vector	rot_point;

	rot_mat = make_matrix3(make_vector(1, 0, 0),
			make_vector(0, cos(cam->angle), -sin(cam->angle)),
			make_vector(0, sin(cam->angle), cos(cam->angle)));
	rot_point = matvec(&rot_mat, point);
	return (rot_point);
}

t_vector	rotate_point_y(t_camera *cam, t_vector *point)
{
	t_mat		rot_mat;
	t_vector	rot_point;

	rot_mat = make_matrix3(make_vector(cos(cam->angle), 0, sin(cam->angle)),
			make_vector(0, 1, 0),
			make_vector(-sin(cam->angle), 0, cos(cam->angle)));
	rot_point = matvec(&rot_mat, point);
	return (rot_point);
}

t_vector	rotate_point_z(t_camera *cam, t_vector *point)
{
	t_mat		rot_mat;
	t_vector	rot_point;

	rot_mat = make_matrix3(make_vector(cos(cam->angle), -sin(cam->angle), 0),
			make_vector(sin(cam->angle), cos(cam->angle), 0),
			make_vector(0, 0, 1));
	rot_point = matvec(&rot_mat, point);
	return (rot_point);
}
