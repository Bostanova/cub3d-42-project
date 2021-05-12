/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:02:49 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:09:55 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(char *line, t_all *all, t_check *check)
{	
	if (line[0] == '\0' && all->is_map_flag == 0)
		return ;
	else if (line[0] == 'R' && line[1] == ' ')
		resolution(line, all, check);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		texture(line, &all->no, all, check);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		texture(line, &all->so, all, check);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		texture(line, &all->we, all, check);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		texture(line, &all->ea, all, check);
	else if (line[0] == 'S' && line[1] == ' ')
		texture(line, &all->spr_tex, all, check);
	else if (line[0] == 'F' && line[1] == ' ')
		floor_ceil(line, &all->floor_colour, all, check);
	else if (line[0] == 'C' && line[1] == ' ')
		floor_ceil(line, &all->ceil_colour, all, check);
	else if (line[0] == ' ' || line[0] == '1' || all->is_map_flag == 1)
		map_parse(line, all, check, 0);
	else
		error(-5, all);
}

void	parse_file(t_all *all)
{
	t_check	check;
	char	*line;
	int		map_line;

	map_line = 0;
	init_check(&check);
	line = NULL;
	all->gnl = get_next_line(all->fd, &line);
	while (all->gnl)
	{
		if (all->gnl == -1)
			error(-2, all);
		parse_texture(line, all, &check);
		if (all->is_map_flag == 1)
		{
			map_line = ft_strlen(line);
			if (all->map_w < map_line)
				all->map_w = map_line;
		}
		free(line);
		all->gnl = get_next_line(all->fd, &line);
	}
	free(line);
	check_options(&check, all);
}
