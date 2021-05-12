/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:14:21 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:14:38 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_line(t_all *all, void **content)
{
	char	*res;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *content;
	j = all->map_w - ft_strlen(*content);
	res = malloc(sizeof(char) * j + 1);
	if (!res)
		error(-4, all);
	res[j] = '\0';
	while (j--)
		res[i++] = ' ';
	*content = ft_strjoin(*content, res);
	if (!(*content))
	{
		free(res);
		error(-4, all);
	}
	free(res);
	free(tmp);
}

void	check_unit(t_all *all, int x, int y)
{
	if (all->map[y][x] == ' ' || all->map[y][x] == '1')
		return ;
	if (x == 0 || y == 0 || x == (all->map_w - 1)
		|| y == (all->map_h - 1))
		error(-5, all);
	if (all->map[y + 0][x + 1] == ' ' || all->map[y + 0][x - 1] == ' '
		|| all->map[y + 1][x + 0] == ' ' || all->map[y - 1][x + 0] == ' '
		|| all->map[y - 1][x + 1] == ' ' || all->map[y - 1][x - 1] == ' '
		|| all->map[y + 1][x - 1] == ' ' || all->map[y + 1][x + 1] == ' ')
		error(-5, all);
	if (ft_strchr(DIR, all->map[y][x]))
	{
		all->posX = x;
		all->posY = y;
	}	
}

void	check_map(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < all->map_h)
	{
		x = 0;
		while (x < all->map_w)
		{
			check_unit(all, x, y);
			x++;
		}
		y++;
	}
}

void	map(t_all *all)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = all->head;
	all->map = ft_calloc(all->map_h + 1, sizeof(char *));
	if (!all->map)
		error(-4, all);
	while (tmp)
	{
		if ((int)(ft_strlen(tmp->content)) < all->map_w)
			fill_line(all, &tmp->content);
		all->map[i++] = tmp->content;
		tmp = tmp->next;
	}
	all->map[i] = 0;
	check_map(all);
	all->beam_array = ft_calloc(all->map_w + 1, sizeof(double) * \
	all->win_w);
	if (!all->beam_array)
		error(-4, all);
}
