/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:26:40 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:36:43 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_w(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY + s)][(int)(all->posX + c)] != '1' \
		&& all->map[(int)(all->posY + s)][(int)(all->posX + c)] != '2')
	{
		all->posY = all->posY + (sin(all->plr_dir) / 2) * 1 / 8;
		all->posX = all->posX + (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	change_s(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY - s)][(int)(all->posX - c)] != '1' \
		&& all->map[(int)(all->posY - s)][(int)(all->posX - c)] != '2')
	{
		all->posY = all->posY - (sin(all->plr_dir) / 2) * 1 / 8;
		all->posX = all->posX - (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	change_a(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY - c)][(int)(all->posX + s)] != '1' \
		&& all->map[(int)(all->posY - c)][(int)(all->posX + s)] != '2')
	{
		all->posX = all->posX + (sin(all->plr_dir) / 2) * 1 / 8;
		all->posY = all->posY - (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	change_d(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY + c)][(int)(all->posX - s)] != '1' \
		&& all->map[(int)(all->posY + c)][(int)(all->posX - s)] != '2')
	{
		all->posX = all->posX - (sin(all->plr_dir) / 2) * 1 / 8;
		all->posY = all->posY + (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

int	key_press(int key, t_all *all)
{
	if (key == 53)
		exit_window(all);
	if (key == 13 || key == 126)
		change_w(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	if (key == 1 || key == 125)
		change_s(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	else if (key == 0)
		change_a(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	else if (key == 2)
		change_d(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	else if (key == 124)
		all->plr_dir += 0.03;
	else if (key == 123)
		all->plr_dir -= 0.03;
	if (all->plr_dir > M_PI * 2)
		all->plr_dir -= M_PI * 2;
	if (all->plr_dir < 0)
		all->plr_dir += M_PI * 2;
	draw_n_synx(all);
	return (0);
}
