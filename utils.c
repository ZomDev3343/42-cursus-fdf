/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:54:16 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 15:27:00 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vars(t_vars *vars)
{
	free(vars->cam);
	free(vars->points);
	free(vars->mlx);
	free(vars);
}

void	print_vector(char *name, t_vector *v)
{
	ft_printf("%s :\nX: %d\nY:%d\nZ:%d\n", name, v->x, v->y, v->z);
}
