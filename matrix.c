/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:54 by marvin            #+#    #+#             */
/*   Updated: 2024/02/07 16:18:03 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	make_matrix3(t_vector x, t_vector y, t_vector z)
{
	t_mat	matrix;

	matrix.x = x;
	matrix.y = y;
	matrix.z = z;
	return (matrix);
}

void	add_matrix(t_mat *m1, t_mat *m2)
{
	add_vector(&(m1->x), &(m2->x));
	add_vector(&(m1->y), &(m2->y));
	add_vector(&(m1->z), &(m2->z));
}

t_vector	matvec(t_mat *m, t_vector *v)
{
	t_vector	res;

	res.x = m->x.x * v->x + m->y.x * v->y + m->z.x * v->z;
	res.y = m->x.y * v->x + m->y.y * v->y + m->z.y * v->z;
	res.z = m->x.z * v->x + m->y.z * v->y + m->z.z * v->z;
	return (res);
}
