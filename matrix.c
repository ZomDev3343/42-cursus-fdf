/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:34:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector   *make_matrix3(t_vector x, t_vector y, t_vector z)
{
    t_vector    matrix[3];

    matrix[0] = x;
    matrix[1] = y;
    matrix[2] = z;
    return (matrix);
}

t_vector    *add_matrix(t_vector *m1, t_vector *m2)
{
    int i;

    i = -1;
    while (++i < 3)
    {
        
    }
}