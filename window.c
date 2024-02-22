/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:36:05 by tohma             #+#    #+#             */
/*   Updated: 2024/02/22 15:09:56 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	return (exit(0), 0);
}

int	manage_input(int keycode, t_vars *vars)
{
	ft_printf("Keycode : %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		close_window(vars);
	if (keycode == KEY_P)
		vars->cam->zoom += 1.0;
	else if (keycode == KEY_O)
		vars->cam->zoom = ft_dmax(vars->cam->zoom - 1.0, -24.0);
	if (keycode == KEY_A)
		vars->cam->angle += 1.0;
	else if (keycode == KEY_E)
		vars->cam->angle -= 1.0;
}
