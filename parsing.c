/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:19:33 by tohma             #+#    #+#             */
/*   Updated: 2024/02/13 16:12:09 by tohma            ###   ########.fr       */
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

static int	parse_map_size(char *map_file, t_vars *vars)
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
	return (vars->map_height = height, vars->map_width = prev_width,
		vars->map_size = height * prev_width, (fd), TRUE);
}

static int	parse_points(char *map_content, t_vars *vars)
{
	char	**parts;
	int		i;
	int		j;

	vars->points = (t_vector *) ft_calloc(vars->cam, sizeof(t_vector));
	if (vars->points)
		return (0);
	i = -1;
	j = 0;
	ft_strrepl(map_content, '\n', ' ');
	parts = ft_split(map_content, ' ');
	if (!parts)
		return (ft_printf("Split error!\n"), 0);
	// TODO Verifier le contenu de chaque case de la map avec atoi
	// TODO Finir le parsing
}

int	parse_map(char *map_file, t_vars *vars)
{
	char	*f_content;
	char	**f_parts;

	f_content = get_file_content(map_file);
	if (!f_content)
		return (0);
	if (!f_parts)
		return (free(f_content), ft_printf("Split Error!\n", FALSE));
	if (!parse_map_size(map_file, vars))
		return (free(f_content), FALSE);
	if (!parse_points(f_content, vars))
		return (free(f_content), FALSE);
}