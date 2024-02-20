/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:54:16 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 22:46:58 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vars(t_vars *vars)
{
	ft_free(vars->cam);
	ft_free(vars->points);
	ft_free(vars->drawn_points);
	ft_free(vars->mlx);
	ft_free(vars);
}
