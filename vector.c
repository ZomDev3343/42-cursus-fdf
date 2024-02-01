/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:34:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector    make_vector(int x, int y, int z)
{
    t_vector    res;

    res.x = x;
    res.y = y;
    res.z = z;
    return (res);
}

void    add_vector(t_vector *v1, t_vector *v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
    v1->z += v2->z;
}

void    mult_vector(t_vector *v1, t_vector *v2)
{
    v1->x *= v2->x;
    v1->y *= v2->y;
    v1->z *= v2->z;
}