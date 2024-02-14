/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:00 by tohma             #+#    #+#             */
/*   Updated: 2024/02/14 16:52:22 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_loop_hooks(t_vars *vars)
{
	
}

static void	put_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 2, 1L << 0, manage_input, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	put_loop_hooks(vars);
}

static void	fdf(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	vars->mlx_win = mlx_new_window(vars->mlx, vars->win_width,
			vars->win_height, "FDF");
	if (!vars->mlx_win)
		return ;
	put_hooks(vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (ac != 2)
		return (ft_printf("You must give one (and only) file name!\n"), 1);
	else
	{
		setup_vars(&vars);
		fdf(vars);
		free_vars(vars);
	}
	return (0);
}