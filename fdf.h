/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/02/13 15:24:35 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/ft.h"
# include "mlx/mlx.h"
# include "math.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_mat
{
	t_vector	c1;
	t_vector	c2;
	t_vector	c3;
}	t_mat;

typedef struct s_cam
{
	double	angle;
	double	near;
	double	far;
	double	fov;
	int		x;
	int		y;
}	t_cam;

typedef struct s_vars
{
	int			map_width;
	int			map_height;
	int			map_size;
	t_cam		*cam;
	t_vector	*points;
}	t_vars;

void	setup_vars(t_vars **vars);
int		parse_map_size(char *map_file, t_vars *vars);
void	free_vars(t_vars *vars);

#endif
