/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/02/21 12:04:21 by tohma            ###   ########.fr       */
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

# include <stdio.h>

/* FDF */

void		setup_vars(t_vars **vars);
void		free_vars(t_vars *vars);
void		print_vector(char *name, t_vector *v);
void		print_mat(t_mat *mat);
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
void		draw_fsquare(t_img *img, t_draw_info info, int size);

/* Render */

int			render_frame(t_vars *vars);

/* Window Utils */

int			close_window(t_vars *vars);
int			manage_input(int keycode, t_vars *vars);

#endif
