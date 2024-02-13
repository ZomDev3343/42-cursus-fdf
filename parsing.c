/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:19:33 by tohma             #+#    #+#             */
/*   Updated: 2024/02/13 14:13:25 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_line_parts_size(char *line)
{
	char	**line_parts;
	int		size;

	ft_strrepl(line, '\n', ' ');
	line_parts = ft_split(line, ' ');
	size = get_parts_size(line_parts);
	return (free_parts(line_parts), size);
}

int	parse_map_size(char *map_file, t_vars *vars)
{
	char	*cur_line;
	int		prev_width;
	int		height;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Can't access the map file!\n"), FALSE);
	cur_line = get_next_line(fd);
	if (!cur_line)
		return (FALSE);
	height = 1;
	prev_width = get_line_parts_size(cur_line);
	free(cur_line);
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		if (prev_width != get_line_parts_size(cur_line))
			return (close(fd), FALSE);
		free(cur_line);
		cur_line = get_next_line(fd);
		height++;
	}
	return (vars->height = height, vars->width = prev_width, close(fd), TRUE);
}
