/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:37:21 by truello           #+#    #+#             */
/*   Updated: 2024/01/17 19:46:38 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/* Split the given line and returns if all the parts contain int values */
t_bool	has_int_parts(char *line, char delimiter)
{
	char	**parts;
	int		i;

	i = -1;
	parts = ft_split(line, delimiter);
	while (parts[++i])
		if (!ft_strncmp(parts[i], "0", 1) && ft_atoi(parts[i]) == 0)
			return (free_parts(parts), FALSE);
	free_parts(parts);
	return (TRUE);
}

/* Doesnt free 'parts' */
t_bool	is_int_parts(char **parts)
{
	int		i;

	i = -1;
	while (parts[++i])
		if (!ft_strcmp(parts[i], "0") && ft_atoi(parts[i]) == 0)
			return (FALSE);
	return (TRUE);
}
