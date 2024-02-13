/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:11:00 by tohma             #+#    #+#             */
/*   Updated: 2024/02/13 14:09:04 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (ac != 2)
		return (ft_printf("You must give one (and only) file name!\n"), 1);
	else
	{
		setup_vars(&vars);
		free_vars(vars);
	}
	return (0);
}