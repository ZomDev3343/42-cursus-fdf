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

typedef struct s_interact
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
}	t_interact;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	int			win_width;
	int			win_height;
	t_interact	*cam;
}	t_vars;

typedef struct s_img
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_vars	*vars;
}   t_img;

int			manage_input(int keycode, t_vars *vars);

int			close_window(t_vars *vars);
int			put_hooks(t_vars *vars);

/* Render */
int			render_frame(t_vars *vars);

/* Draw */
void    	draw_pixel(t_img *img, int x, int y, int color);
void    	draw_square(t_img *img, int x, int y, int size);

/* Interact */
t_interact	create_interact(int x, int y, int size_x, int size_y);
void		center_pos(t_vars *vars, t_interact *obj);

/* Utils */
void		free_vars(t_vars *vars);

#endif
