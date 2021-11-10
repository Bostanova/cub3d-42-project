/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:26:40 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 13:21:48 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_all *all)
{
	if (key == 53)
		exit_window(all);
	if (key == 13 || key == 126)
		step_up(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	if (key == 1 || key == 125)
		step_back(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	else if (key == 0)
		step_left(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
	else if (key == 2)
		step_right(all, cos(all->plr_dir) / 2, sin(all->plr_dir) / 2);
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

void	step_up(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY + s)][(int)(all->posX + c)] != '1' \
		&& all->map[(int)(all->posY + s)][(int)(all->posX + c)] != '2')
	{
		all->posY = all->posY + (sin(all->plr_dir) / 2) * 1 / 8;
		all->posX = all->posX + (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	step_back(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY - s)][(int)(all->posX - c)] != '1' \
		&& all->map[(int)(all->posY - s)][(int)(all->posX - c)] != '2')
	{
		all->posY = all->posY - (sin(all->plr_dir) / 2) * 1 / 8;
		all->posX = all->posX - (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	step_left(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY - c)][(int)(all->posX + s)] != '1' \
		&& all->map[(int)(all->posY - c)][(int)(all->posX + s)] != '2')
	{
		all->posX = all->posX + (sin(all->plr_dir) / 2) * 1 / 8;
		all->posY = all->posY - (cos(all->plr_dir) / 2) * 1 / 8;
	}
}

void	step_right(t_all *all, double c, double s)
{
	if (all->map[(int)(all->posY + c)][(int)(all->posX - s)] != '1' \
		&& all->map[(int)(all->posY + c)][(int)(all->posX - s)] != '2')
	{
		all->posX = all->posX - (sin(all->plr_dir) / 2) * 1 / 8;
		all->posY = all->posY + (cos(all->plr_dir) / 2) * 1 / 8;
	}
}
