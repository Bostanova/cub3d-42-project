/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:29:51 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 12:11:20 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	vert_obstacle(t_all *all, double Y, int X, double ray)
{
	if (cos(all->angle) == 0)
		return (ray);
	X = (int)all->posX + 1;
	all->ray_vX = 1;
	if (cos(all->angle) < 0)
	{
		X = (int)all->posX;
		all->ray_vX = -1;
	}
	all->ray_vY = tan(all->angle);
	Y = all->posY + (X - all->posX) * tan(all->angle);
	while (X > 0 && X < all->map_w)
	{
		if (Y < 0 || Y >= all->map_h)
			break ;
		if (all->map[(int)Y][(int)X - (all->ray_vX == -1 ? 1 : 0)] == '1')
		{
			ray = (X - all->posX) / cos(all->angle);
			break ;
		}
		X += all->ray_vX;
		Y += all->ray_vY * all->ray_vX;
	}
	all->ray_pos_y = Y;
	return (ray);
}

double	hor_obstacle(t_all *all, double X, int Y, double ray)
{
	if (sin(all->angle) == 0)
		return (ray);
	all->ray_hY = -1;
	Y = (int)all->posY;
	if (sin(all->angle) > 0)
	{
		all->ray_hY = 1;
		Y = (int)all->posY + 1;
	}
	all->ray_hX = 1 / tan(all->angle);
	X = all->posX + (Y - all->posY) * all->ray_hX;
	while (Y > 0 && Y < all->map_h)
	{
		if (X < 0 || X >= all->map_w)
			break ;
		if (all->map[(int)Y - (all->ray_hY == -1 ? 1 : 0)][(int)X] == '1')
		{
			ray = (Y - all->posY) / sin(all->angle);
			break ;
		}
		Y += all->ray_hY;
		X += all->ray_hX * all->ray_hY;
	}
	all->ray_pos_x = X;
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
