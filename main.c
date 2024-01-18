/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:12 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 17:06:46 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (ac != 1)
	{
		vars = ft_calloc(sizeof(t_vars), 1);
		vars->map = parse_map(av[1]);
		if (!vars->map)
			return (ft_printf("Error while parsing the map!\n"), 1);
		ft_printf("Parsing OK!\n");
		print_map_infos(vars->map);
		vars->mlx = mlx_init();
		if (!vars->mlx)
			return (1);
		//vars->mlx_win = mlx_new_window(vars->mlx, 800, 600, "FDF");
		//mlx_hook(vars->mlx, 2, 0, close, vars);
		//mlx_loop(vars->mlx);
		/*free(vars->mlx);
		free_map(vars->map);
		free(vars);*/
	}
	return (0);
}
