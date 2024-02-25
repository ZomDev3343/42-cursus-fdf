/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:17 by tohma             #+#    #+#             */
/*   Updated: 2024/02/24 19:28:17 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATH_H
# define FDF_MATH_H

# include "fdf_struct.h"

# define PI 3.14159

/* Vectors */

t_vector	newvec(double x, double y, double z);
t_vector	addvec(t_vector v1, t_vector v2);
t_vector	mulvec(t_vector v, double n);
double		rowcol(t_vector	v1, t_vector v2);

/* Matrices */

t_mat		newmat(t_vector c1, t_vector c2, t_vector c3);
t_vector	matvec(t_mat mat, t_vector v);
t_mat		matmat(t_mat m1, t_mat	m2);
t_vector	matrow(t_mat *mat, int rowi);

/* Transformations */

t_vector	project_point(t_vector *point);
t_vector	iso_point(t_cam *cam, t_vector *point);
t_vector	curvlinear_point(t_cam *cam, t_vector *point);

/* Rotations */

t_mat		rotx_mat(double angle);
t_mat		roty_mat(double angle);
t_mat		rotz_mat(double angle);

#endif