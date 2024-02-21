/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:15:04 by tohma             #+#    #+#             */
/*   Updated: 2024/02/21 16:09:54 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Creates a matrix variable
*/
t_mat	newmat(t_vector c1, t_vector c2, t_vector c3)
{
	t_mat	mat;

	mat.c1 = c1;
	mat.c2 = c2;
	mat.c3 = c3;
	return (mat);
}

/*
	Multiplies a matrix by a vector
	Ex: projection/rotation matrices purposes
*/
t_vector	matvec(t_mat mat, t_vector v)
{
	t_vector	res;

	res.x = mat.c1.x * v.x + mat.c2.x * v.y + mat.c3.x * v.z;
	res.y = mat.c1.y * v.x + mat.c2.y * v.y + mat.c3.y * v.z;
	res.z = mat.c1.z * v.x + mat.c2.z * v.y + mat.c3.z * v.z;
	return (res);
}

t_vector	matrow(t_mat *mat, int rowi)
{
	if (rowi == 1)
		return (newvec(mat->c1.x, mat->c2.x, mat->c3.x));
	else if (rowi == 2)
		return (newvec(mat->c1.y, mat->c2.y, mat->c3.y));
	else
		return (newvec(mat->c1.z, mat->c2.z, mat->c3.z));
}

t_mat	matmat(t_mat m1, t_mat	m2)
{
	t_mat	res;

	res.c1.x = rowcol(matrow(&m1, 1), m2.c1);
	res.c2.x = rowcol(matrow(&m1, 1), m2.c2);
	res.c3.x = rowcol(matrow(&m1, 1), m2.c3);
	res.c1.y = rowcol(matrow(&m1, 2), m2.c1);
	res.c2.y = rowcol(matrow(&m1, 2), m2.c2);
	res.c3.y = rowcol(matrow(&m1, 2), m2.c3);
	res.c1.z = rowcol(matrow(&m1, 3), m2.c1);
	res.c2.z = rowcol(matrow(&m1, 3), m2.c2);
	res.c3.z = rowcol(matrow(&m1, 3), m2.c3);
	return (res);
}
