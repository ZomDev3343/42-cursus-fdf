/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:15:04 by tohma             #+#    #+#             */
/*   Updated: 2024/02/14 10:23:08 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	make_matrix(t_vector c1, t_vector c2, t_vector c3)
{
	t_mat	mat;

	mat.c1 = c1;
	mat.c2 = c2;
	mat.c3 = c3;
	return (mat);
}

t_vector	matvec(t_mat mat, t_vector v)
{
	t_vector	res;

	res.x = mat.c1.x * v.x + mat.c2.x * v.y + mat.c3.x * v.z;
	res.y = mat.c1.y * v.x + mat.c2.y * v.y + mat.c1.y * v.z;
	res.z = mat.c1.z * v.x + mat.c2.z * v.y + mat.c3.z * v.z;
	return (res);
}
