/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/17 17:41:59 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/ft.h"
# include "minilibx_macos/mlx.h"

/* Map */

typedef struct s_map
{
	int	width;
	int	height;
	int	**grid;
}	t_map;

void	free_map(t_map *map);
t_map	*create_map(int width, int height);
int		parse_map_dimension(char *map_file, int *width, int *height);
int		fill_grid_values(t_map *map, char *map_file);
t_map	*parse_map(char *map_file);
void	print_map_infos(t_map *map);

#endif
