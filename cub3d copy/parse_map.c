/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:12:35 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:36:25 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parse(char *line, t_all *all, t_check *check, int i)
{
	char	*tmp;

	tmp = line;
	while (tmp[i])
	{
		if (!(ft_strrchr(MAP, tmp[i])))
			error(-5, all);
		if (ft_strrchr(DIR, tmp[i]) && check->dir == 0)
		{
			check->dir = 1;
			all->dir = tmp[i];
		}
		else if (ft_strrchr(DIR, tmp[i]) && \
		check->dir == 1)
			error(-5, all);
		if (tmp[i] == '2')
			all->sprites++;
		i++;
	}
	all->is_map_flag = 1;
	if (line[0] == '\0')
		error(-5, all);
	ft_lstadd_back(&all->head, ft_lstnew(ft_strdup(line)));
	all->map_h += 1;
}
