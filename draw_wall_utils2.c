/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:29:51 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:29:53 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	vert_obstacle(t_all *all, double nearY, int nearX, \
double ray)
{
	if (cos(all->angle) == 0)
		return (ray);
	nearX = (int)all->posX + 1;
	all->v_dX = 1;
	if (cos(all->angle) < 0)
	{
		nearX = (int)all->posX;
		all->v_dX = -1;
	}
	all->v_dY = tan(all->angle);
	nearY = all->posY + (nearX - all->posX) * tan(all->angle);
	while (nearX > 0 && nearX < all->map_w)
	{
		if (nearY < 0 || nearY >= all->map_h)
			break ;
		if (all->map[(int)nearY][(int)nearX - (all->v_dX == -1 ? 1 : 0)] == '1')
		{
			ray = (nearX - all->posX) / cos(all->angle);
			break ;
		}
		nearX += all->v_dX;
		nearY += all->v_dY * all->v_dX;
	}
	all->ray_pos_y = nearY;
	return (ray);
}

double	hor_obstacle(t_all *all, double nearX, int nearY, \
double ray)
{
	if (sin(all->angle) == 0)
		return (ray);
	all->h_dY = -1;
	nearY = (int)all->posY;
	if (sin(all->angle) > 0)
	{
		all->h_dY = 1;
		nearY = (int)all->posY + 1;
	}
	all->h_dX = 1 / tan(all->angle);
	nearX = all->posX + (nearY - all->posY) * all->h_dX;
	while (nearY > 0 && nearY < all->map_h)
	{
		if (nearX < 0 || nearX >= all->map_w)
			break ;
		if (all->map[(int)nearY - (all->h_dY == -1 ? 1 : 0)][(int)nearX] == '1')
		{
			ray = (nearY - all->posY) / sin(all->angle);
			break ;
		}
		nearY += all->h_dY;
		nearX += all->h_dX * all->h_dY;
	}
	all->ray_pos_x = nearX;
	return (ray);
}

void	offset_x(double vert_obst, double hor_obst, t_all *all)
{
	if (vert_obst < hor_obst)
		all->x_offset = all->ray_pos_y - (int)all->ray_pos_y;
	else
		all->x_offset = all->ray_pos_x - (int)all->ray_pos_x;
}

void	hits_side(double vert_obst, double hor_obst, t_all *all)
{
	if (vert_obst < hor_obst)
	{
		if (all->ray_pos_x < all->posX)
			all->ray_hit_side = 3;
		else
			all->ray_hit_side = 4;
	}
	else
	{
		if (all->ray_pos_y < all->posY)
			all->ray_hit_side = 1;
		else
			all->ray_hit_side = 2;
	}
}
