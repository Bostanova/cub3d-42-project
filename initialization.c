/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:58:40 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:38:21 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_all *all)
{
	all->so = "0";
	all->no = "0";
	all->ea = "0";
	all->we = "0";
	all->win_w = 0;
	all->win_h = 0;
	all->map_w = 0;
	all->map_h = 0;
	all->head = NULL;
	all->sprites = 0;
	all->is_map_flag = 0;
	all->bmp = 0;
	all->spr_tex = "0";
	all->ceil_colour = -1;
	all->floor_colour = -1;
}

void	init_check(t_check *check)
{
	check->dir = 0;
	check->so = 0;
	check->no = 0;
	check->ea = 0;
	check->we = 0;
	check->s = 0;
	check->c = 0;
	check->f = 0;
	check->r = 0;
}

void	init_player(t_all *all)
{
	if (all->dir == 'N')
		all->plr_dir = M_PI_2 * 3;
	else if (all->dir == 'S')
		all->plr_dir = M_PI_2;
	else if (all->dir == 'W')
		all->plr_dir = M_PI;
	else if (all->dir == 'E')
		all->plr_dir = M_PI * 2;
	all->ray_step = (M_PI / 3) / all->win_w;
	all->posX = all->posX + 0.5;
	all->posY = all->posY + 0.5;
	all->proj_plane = all->win_w / 2 / tan(M_PI_2 / 3);
}

void	init_texture(t_all *all)
{
	all->tex_path[0] = all->spr_tex;
	all->tex_path[1] = all->no;
	all->tex_path[2] = all->so;
	all->tex_path[3] = all->we;
	all->tex_path[4] = all->ea;
}
