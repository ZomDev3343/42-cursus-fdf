/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:19:33 by tohma             #+#    #+#             */
/*   Updated: 2024/02/23 13:14:48 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Returns the amount of parts of a line
	separated by a space
*/
static int	get_line_parts_size(char *line)
{
	char	**line_parts;
	int		size;

	ft_strrepl(line, '\n', ' ');
	line_parts = ft_split(line, ' ');
	size = get_parts_size(line_parts);
	return (free_parts(line_parts), size);
}

/*
	Gets the height and width of a map
	Returns TRUE or FALSE according to the
	correct (or not) format of the map
*/
static int	parse_map_size(char *map_file, t_vars *vars)
{
	char	*cur_line;
	int		fd;
	int		w;
	int		h;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Can't access the map file!\n"), FALSE);
	cur_line = get_next_line(fd);
	if (!cur_line)
		return (FALSE);
	h = 1;
	w = get_line_parts_size(cur_line);
	free(cur_line);
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		if (w != get_line_parts_size(cur_line)
			|| !has_int_parts(cur_line, ' '))
			return (ft_clear_gnl(fd), free(cur_line), close(fd), FALSE);
		free(cur_line);
		cur_line = get_next_line(fd);
		h++;
	}
	return (vars->map_height = h, vars->map_width = w, close(fd), TRUE);
}

/*
	Gets all the different points of the map with their values
*/
static int	parse_points(char *map_content, t_vars *vars)
{
	char	**parts;
	int		i;
	int		j;
	int		point_idx;

	vars->points = (t_vector *) ft_calloc(vars->map_size, sizeof(t_vector));
	if (!vars->points)
		return (ft_printf("Points malloc error\n"), FALSE);
	ft_strrepl(map_content, '\n', ' ');
	parts = ft_split(map_content, ' ');
	if (!parts)
		return (ft_printf("Split error!\n"), FALSE);
	i = -1;
	while (++i < vars->map_height)
	{
		j = -1;
		while (++j < vars->map_width)
		{
			point_idx = i * vars->map_width + j;
			vars->points[point_idx] = newvec(25 * j,
					25 * i,
					ft_atoi(parts[point_idx]));
		}
	}
	return (free_parts(parts), TRUE);
}

static void	init_drawn_points(t_vars *vars)
{
	int	i;

	i = -1;
	vars->drawn_points = (t_vector *) ft_calloc(vars->map_size,
			sizeof(t_vector));
	if (!vars->drawn_points)
		return ;
	while (++i < vars->map_size)
		vars->drawn_points[i] = vars->points[i];
}

/*
	Parses the map given via the map file path
*/
int	parse_map(char *map_file, t_vars *vars)
{
	char	*f_content;

	f_content = get_file_content(map_file);
	if (!f_content)
		return (0);
	if (!parse_map_size(map_file, vars))
		return (free(f_content), FALSE);
	vars->map_size = vars->map_height * vars->map_width;
	if (!parse_points(f_content, vars))
		return (free(f_content), FALSE);
	init_drawn_points(vars);
	if (!vars->drawn_points)
		return (free(f_content), FALSE);
	return (free(f_content), TRUE);
}
