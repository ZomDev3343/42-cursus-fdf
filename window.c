/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:36:05 by tohma             #+#    #+#             */
/*   Updated: 2024/02/14 10:40:53 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	exit(0);
}

void	manage_input(t_vars *vars)
{
	
}

