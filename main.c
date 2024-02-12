/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:12 by truello           #+#    #+#             */
/*   Updated: 2024/02/08 16:10:09 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_vars(t_vars *vars)
{
	vars->cam = make_camera();
	vars->win_width = 800;
	vars->win_height = 600;
}

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (ac != 1)
	{
		vars = (t_vars *) ft_calloc(1, sizeof(t_vars));
		setup_vars(vars);
		vars->map = parse_map(av[1]);
		if (!vars->map)
			return (free(vars), ft_printf("Error while parsing the map!\n"), 1);
		ft_printf("Parsing OK!\n");
		print_map_infos(vars->map);
		vars->mlx = mlx_init();
		if (!vars->mlx)
			return (1);
		vars->mlx_win = mlx_new_window(vars->mlx, vars->win_width,
				vars->win_height, "FDF");
		put_hooks(vars);
		mlx_loop(vars->mlx);
	}
	return (0);
}
