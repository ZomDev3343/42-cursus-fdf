/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:54 by marvin            #+#    #+#             */
/*   Updated: 2024/02/01 16:22:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*make_matrix3(t_vector x, t_vector y, t_vector z)
{
	t_vector matrix[3];

	matrix[0] = x;
	matrix[1] = y;
	matrix[2] = z;
	return (matrix);
}

void		add_matrix(t_vector *m1, t_vector *m2)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		m1[i].x += m2[i].x;
		m1[i].y += m2[i].y;
		m1[i].z += m2[i].z;
	}
}