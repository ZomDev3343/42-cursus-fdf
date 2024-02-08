/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/02/08 13:10:46 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/ft.h"
# include "mlx/mlx.h"
# include "math.h"

/* Map */

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct s_mat
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
}	t_mat;

typedef struct s_map
{
	int			width;
	int			height;
	int			**grid;
	t_vector	*points;
}	t_map;

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
}	t_img;

typedef struct s_camera
{
	int	fov;
	int	far;
	int	aspect;
	int	angle;
	int	x;
	int	y;
}	t_camera;

void		free_map(t_map *map);
int			parse_map_dimension(char *map_file, int *width, int *height);
int			fill_grid_values(t_map *map, char *map_file);
t_map		*parse_map(char *map_file);
void		print_map_infos(t_map *map);

int			manage_input(int keycode, t_vars *vars);

int			close_window(t_vars *vars);
int			put_hooks(t_vars *vars);

/* Camera */
t_camera	make_camera(void);

/* Render */
int			render_frame(t_vars *vars);

/* Draw */
void		draw_pixel(t_img *img, int x, int y, int color);
void		draw_square(t_img *img, int x, int y, int size);
void		draw_line(t_img *img, t_vector from, t_vector to);

/* Interact */
t_interact	create_interact(int x, int y, int size_x, int size_y);
void		center_pos(t_vars *vars, t_interact *obj);

/* Vector */

t_vector	make_vector(int x, int y, int z);
void		add_vector(t_vector *v1, t_vector *v2);
void		mult_vector(t_vector *v1, int n);

/* Matrix */

t_mat		make_matrix3(t_vector x, t_vector y, t_vector z);
void		add_matrix(t_mat *m1, t_mat *m2);

/* Utils */
void		free_vars(t_vars *vars);

#endif
