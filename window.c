/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:20:19 by truello           #+#    #+#             */
/*   Updated: 2024/02/05 15:21:39 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	exit(0);
	return (0);
}

static int	put_loop_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, render_frame, vars);
}

int	put_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, manage_input, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	put_loop_hooks(vars);
}
