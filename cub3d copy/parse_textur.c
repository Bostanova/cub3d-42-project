/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:10:40 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:36:15 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture(char *line, char **path, t_all *all, t_check *check)
{
	char	**list;

	if ((line[0] == 'S' && line[1] == 'O' && check->so == 1)
		|| (line[0] == 'N' && check->no == 1)
		|| (line[0] == 'S' && check->s == 1)
		|| (line[0] == 'W' && check->we == 1)
		|| (line[0] == 'E' && check->ea == 1))
		error(-11, all);
	list = ft_split(line, ' ');
	if ((num_words(list)) != 2)
	{
		clean(list);
		error(-6, all);
	}
	*path = ft_strdup(list[1]);
	if (!(*path))
	{
		clean(list);
		error(-4, all);
	}
	set_checking(check, line);
	clean(list);
}
