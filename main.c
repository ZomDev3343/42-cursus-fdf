/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:00 by tohma             #+#    #+#             */
/*   Updated: 2024/02/26 15:41:01 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	TODO Faire le systeme pour changer la couleur en fonction
	de la hauteur d'un pixel
*/

static void	put_loop_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, render_frame, vars);
}

static void	put_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, manage_input, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	put_loop_hooks(vars);
}

static void	fdf(t_vars *vars)
{
	ft_printf("Map Width: %d, Map Height: %d\n",
		vars->map_width, vars->map_height);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	vars->mlx_win = mlx_new_window(vars->mlx, vars->win_width,
			vars->win_height, "FDF");
	if (!vars->mlx_win)
		return ;
	set_top_bottom(vars);
	put_hooks(vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
		return (ft_printf("You must give one (and only) file name!\n"), 1);
	else
	{
		setup_vars(&vars);
		if (parse_map(av[1], vars))
			fdf(vars);
		else
			ft_printf("Map Error\n");
		free_vars(vars);
	}
	return (0);
}
