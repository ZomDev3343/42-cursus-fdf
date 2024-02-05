/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:54 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 14:34:26 by tohma            ###   ########.fr       */
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

void	mul_mat(t_mat *m, t_vector *v)
{
	
}