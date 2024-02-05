/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:20:53 by tohma             #+#    #+#             */
/*   Updated: 2024/02/05 15:21:19 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	make_vector(int x, int y, int z)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

void	add_vector(t_vector *v1, t_vector *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void	mult_vector(t_vector *v1, int n)
{
	v1->x *= n;
	v1->y *= n;
	v1->z *= n;
}
