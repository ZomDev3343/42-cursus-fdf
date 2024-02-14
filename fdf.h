/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/02/14 17:01:54 by tohma            ###   ########.fr       */
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

/* FDF */

void	setup_vars(t_vars **vars);
void	free_vars(t_vars *vars);

/* Window Utils */

int		close_window(t_vars *vars);
int		manage_input(int keycode, t_vars *vars);

#endif
