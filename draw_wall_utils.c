/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:29:14 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 12:25:23 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_to_wall(t_all *all, double begin)
{	
	double	ray;

	all->angle = begin;
	all->hor_obst = hor_obstacle(all, begin, 0, INFINITY);
	all->vert_obst = vert_obstacle(all, begin, 0, INFINITY);
	if (all->vert_obst < all->hor_obst)
		ray = all->vert_obst;
	else
		ray = all->hor_obst;
	hits_side(all->vert_obst, all->hor_obst, all);
	offset_x(all->vert_obst, all->hor_obst, all);
	ray *= cos(begin - all->plr_dir);
	return (ray);
}

void	check_wall(t_all *all)
{
	if (all->wall_h > all->win_h)
		all->wall_h = all->win_h;
}

double	get_dist_y(t_all *all, double tex_st)
{
	double	dist_y;

	dist_y = 0;
	if (all->y_offset > 0)
		dist_y = tex_st * all->y_offset;
	return (dist_y);
}

void	offset_y(t_all *all)
{
	all->y_offset = 0;
	if (all->wall_h > all->win_h)
		all->y_offset = (all->wall_h - all->win_h) / 2;
}

double	check_dist_y(t_all *all, double dsy, double tex_st)
{
	if ((dsy + tex_st) < all->tex_h[all->ray_hit_side])
		dsy = dsy + tex_st;
	return (dsy);
}
