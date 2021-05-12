/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:29:14 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:29:25 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_to_wall(t_all *all, double start)
{	
	double	ray;

	all->angle = start;
	all->hor_obst = hor_obstacle(all, start, 0, INFINITY);
	all->vert_obst = vert_obstacle(all, start, 0, INFINITY);
	if (all->vert_obst < all->hor_obst)
		ray = all->vert_obst;
	else
		ray = all->hor_obst;
	hits_side(all->vert_obst, all->hor_obst, all);
	offset_x(all->vert_obst, all->hor_obst, all);
	ray *= cos(start - all->plr_dir);
	return (ray);
}

void	check_wall(t_all *all)
{
	if (all->wall_h > all->win_h)
		all->wall_h = all->win_h;
}

double	get_dy(t_all *all, double tex_st)
{
	double	dy;

	dy = 0;
	if (all->y_offset > 0)
		dy = tex_st * all->y_offset;
	return (dy);
}

void	offset_y(t_all *all)
{
	all->y_offset = 0;
	if (all->wall_h > all->win_h)
		all->y_offset = (all->wall_h - all->win_h) / 2;
}

double	check_dy(t_all *all, double dy, double tex_st)
{
	if ((dy + tex_st) < all->tex_h[all->ray_hit_side])
		dy = dy + tex_st;
	return (dy);
}
