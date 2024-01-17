/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:12 by truello           #+#    #+#             */
/*   Updated: 2024/01/17 19:57:44 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av, char **env)
{
	t_map	*map;

	if (ac != 1)
	{
		map = parse_map(av[1]);
		if (!map)
			return (ft_printf("Error while parsing the map!\n"), 1);
		ft_printf("Parsing OK!\n");
		print_map_infos(map);
		free_map(map);
	}
	return (0);
}
