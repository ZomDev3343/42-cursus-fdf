/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:20:19 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:31:49 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	manage_input(int keycode, t_vars *vars)
{
	ft_printf("Keycode : %d\n", keycode);
	if (keycode == 65307)
		return (close_window(vars), 0);
	return (0);
}
