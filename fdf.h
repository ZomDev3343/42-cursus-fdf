/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:34:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/ft.h"
# include "mlx/mlx.h"
# include "math.h"

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

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_vars;

int		manage_input(int keycode, t_vars *vars);
void	close_window(t_vars *vars);

#endif
