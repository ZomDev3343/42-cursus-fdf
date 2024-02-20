/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:47:40 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 22:08:02 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	rotx_mat(double angle)
{
	return (newmat(
			newvec(1, 0, 0),
			newvec(0, cos(angle), -sin(angle)),
			newvec(0, sin(angle), cos(angle))
		));
}

t_mat	roty_mat(double angle)
{
	return (newmat(
			newvec(cos(angle), 0, sin(angle)),
			newvec(0, 1, 0),
			newvec(-sin(angle), 0, cos(angle))
		));
}

t_mat	rotz_mat(double angle)
{
	return (newmat(
			newvec(cos(angle), -sin(angle), 0),
			newvec(sin(angle), cos(angle), 0),
			newvec(0, 0, 1)
		));
}


