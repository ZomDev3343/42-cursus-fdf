/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:14 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 17:08:11 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	project_point(t_cam *cam, t_vector *point)
{
	t_mat		proj_mat;
	t_vector	proj_point;

	proj_mat = newmat(newvec(1, 0, 0),
			newvec(0, 1, 0),
			newvec(0, 0, 0));
	proj_point = matvec(proj_mat, *point);
	return (proj_point);
}

t_vector	iso_point(t_cam *cam, t_vector *point)
{
	t_vector	res_point;
	t_mat		rot_mat;
	double		alpha;
	double		beta;
	double		theta;

	alpha = PI / 180.0 * 45.0;
	beta = PI / 180.0 * 0.0;
	theta = PI / 180.0 * cam->angle;
	rot_mat = matmat(rotx_mat(alpha), roty_mat(beta));
	rot_mat = matmat(rot_mat, rotz_mat(theta));
	res_point = matvec(rot_mat, *point);
	return (res_point);
}
