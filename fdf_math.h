/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:39:17 by tohma             #+#    #+#             */
/*   Updated: 2024/02/14 16:43:23 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATH_H
# define FDF_MATH_H

# include "fdf_struct.h"

t_vector	make_vector(double x, double y, double z);
t_vector	addvec(t_vector v1, t_vector v2);
t_vector	mulvec(t_vector v, double n);

t_mat		make_matrix(t_vector c1, t_vector c2, t_vector c3);
t_vector	matvec(t_mat mat, t_vector v);

#endif