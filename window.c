/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:36:05 by tohma             #+#    #+#             */
/*   Updated: 2024/02/20 17:29:44 by tohma            ###   ########.fr       */
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
}
