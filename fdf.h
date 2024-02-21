/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/02/21 17:49:00 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/ft.h"

# include "mlx/mlx.h"

# include "math.h"

# include "fdf_struct.h"
# include "fdf_math.h"
# include "fdf_keys.h"

# define LOW_COLOR 0xD90000
# define HIGH_COLOR 0x00C3EA

/* FDF */

void		setup_vars(t_vars **vars);
void		free_vars(t_vars *vars);

/* Parsing */

int			parse_map(char *map_file, t_vars *vars);

/* Get Neighbors */

t_vector	**get_next_neighbors(t_vars *vars, int point_idx);

/* Draw */

t_draw_info	drawinfo(int start_x, int start_y, int color);
t_draw_info	add_xy_info(t_draw_info *info, int add_x, int add_y);

void		draw_pixel(t_img *img, t_draw_info info);
void		draw_square(t_img *img, t_draw_info info, int size);
void		draw_line(t_img *img, t_vector *from, t_vector *to);

/* Render */

int			render_frame(t_vars *vars);

/* Color */

void		set_top_bottom(t_vars *vars);
int			point_color(double height, t_vars *vars);
int			test_color(double ratio);
/* Window Utils */

int			close_window(t_vars *vars);
int			manage_input(int keycode, t_vars *vars);

#endif
