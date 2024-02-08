/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:29:16 by truello           #+#    #+#             */
/*   Updated: 2024/02/08 13:14:53 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = map->width;
	while (i-- > 0)
	{
		if (map->grid[i])
			ft_free(map->grid[i]);
	}
	ft_free(map->grid);
	ft_free(map->points);
	ft_free(map);
}

static t_map	*create_map(int width, int height)
{
	int		**grid;
	t_map	*map;
	int		i;

	i = -1;
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = width;
	map->height = height;
	grid = (int **) ft_calloc(width, sizeof(int *));
	if (!grid)
		return (free_map(map), NULL);
	while (++i < width)
	{
		grid[i] = (int *) ft_calloc(height, sizeof(int));
		if (!grid[i])
			return (free_map(map), NULL);
	}
	map->grid = grid;
	return (map);
}

static t_vector	*convert_map_to_points(t_map *map)
{
	t_vector	*points;
	int			i;

	points = (t_vector *) ft_calloc(map->height * map->width + 1,
			sizeof(t_vector));
	if (!points)
		return (NULL);
	i = -1;
	while (++i < map->height * map->width)
	{
		points[i].x = i % map->width;
		points[i].y = i / map->width;
		points[i].z = map->grid[i % map->width][i / map->width];
	}
	return (points);
}

t_map	*parse_map(char *map_file)
{
	int		height;
	int		width;
	t_map	*map;

	if (!parse_map_dimension(map_file, &width, &height))
		return (NULL);
	map = create_map(width, height);
	if (!map)
		return (FALSE);
	if (!fill_grid_values(map, map_file))
		return (free_map(map), NULL);
	map->points = convert_map_to_points(map);
	if (!map->points)
		return (free_map(map), NULL);
	return (map);
}
