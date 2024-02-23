/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:36:05 by tohma             #+#    #+#             */
/*   Updated: 2024/02/23 14:52:47 by tohma            ###   ########.fr       */
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

static void	manage_camera_movements(int keycode, t_vars *vars)
{
	if (keycode == KEY_P)
		vars->cam->zoom += 1.0;
	else if (keycode == KEY_O)
		vars->cam->zoom = ft_dmax(vars->cam->zoom - 1.0, -24.0);
	else if (keycode == KEY_Q)
		vars->cam->angle += 3.0;
	else if (keycode == KEY_E)
		vars->cam->angle += -3.0;
	else if (keycode == KEY_A)
		vars->cam->x += -5.0;
	else if (keycode == KEY_D)
		vars->cam->x += 5.0;
	else if (keycode == KEY_S)
		vars->cam->y += 5.0;
	else if (keycode == KEY_W)
		vars->cam->y += -5.0;
	else if (keycode == KEY_C)
		return (vars->cam->x = -vars->win_width / 2,
			vars->cam->y = -vars->win_height / 2, 0);
	else if (keycode == KEY_R)
		vars->cam->angle = 45.0;
}

int	manage_input(int keycode, t_vars *vars)
{
	ft_printf("Keycode : %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		close_window(vars);
	manage_camera_movements(keycode, vars);
	if (keycode == KEY_Z)
		vars->height_mult += 1.0;
	else if (keycode == KEY_X)
		if (vars->height_mult > 1.0)
			vars->height_mult -= 1.0;
}
