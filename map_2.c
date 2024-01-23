/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:57:15 by truello           #+#    #+#             */
/*   Updated: 2024/01/17 19:56:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_parts_amt(char *line)
{
	int		i;
	char	**parts;

	i = 0;
	parts = ft_split(line, ' ');
	if (!parts)
		return (0);
	while (parts[i])
		i++;
	free_parts(parts);
	return (i);
}

int	parse_map_dimension(char *map_file, int *width, int *height)
{
	int		fd;
	char	*line;

	*height = 0;
	*width = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	line = get_next_line(fd);
	if (!line)
		return (FALSE);
	*width = get_parts_amt(line);
	while (line)
	{
		(*height)++;
		if (get_parts_amt(line) != *width || !has_int_parts(line, ' '))
			return (close(fd), free(line), FALSE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (TRUE);
}

int	fill_grid_values(t_map *map, char *map_file)
{
	int		i;
	char	*map_str;
	char	**parts;

	i = -1;
	map_str = get_file_content(map_file);
	if (!map_str)
		return (FALSE);
	ft_strrepl(map_str, '\n', ' ');
	parts = ft_split(map_str, ' ');
	while (parts[++i])
		map->grid[i % map->width][i / map->width] = ft_atoi(parts[i]);
	free_parts(parts);
	free(map_str);
	return (TRUE);
}

void	print_map_infos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	ft_printf("First elem : %d\n", map->grid[0][0]);
	ft_printf("Height : %d, Width : %d\n", map->height, map->width);
	while (++i < map->height)
	{
		while (++j < map->width)
			ft_printf("%d ", map->grid[j][i]);
		j = -1;
		ft_printf("\n");
	}
}
