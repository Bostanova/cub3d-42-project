/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:08:57 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:09:08 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution(char *line, t_all *all, t_check *check)
{
	char	**list;

	if (check->r == 1)
		error(-9, all);
	list = ft_split(line, ' ');
	if ((num_words(list)) != 3)
	{
		clean(list);
		error(-10, all);
	}
	all->win_w = is_num(list[1]);
	all->win_h = is_num(list[2]);
	if (all->win_w == 0 || all->win_h == 0
		|| all->win_w < 0 || all->win_h < 0)
	{
		clean(list);
		error(-10, all);
	}
	check->r = 1;
	clean(list);
}
