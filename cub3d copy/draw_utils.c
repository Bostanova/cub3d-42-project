/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:22:50 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:30:53 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_to_sprite(t_all *all, double dist, int x, int y)
{
	while (y < all->map_h)
	{
		x = 0;
		while (x < all->map_w)
		{
			if (all->map[y][x] == '2')
			{
				if (hypot(all->posX - x, all->posY - y) > dist)
				{
					all->spr_y = y;
					all->spr_x = x;
					dist = hypot(all->posX - ((double)x + 0.5), \
						all->posY - ((double)y + 0.5));
				}
			}
			x++;
		}
		y++;
	}
	all->map[(int)all->spr_y][(int)all->spr_x] = '3';
	return (dist);
}

void	sprite_dir(t_all *all)
{
	all->spr_dir = atan2((all->spr_y + 0.5 - all->posY), \
	(all->spr_x + 0.5 - all->posX));
	while (all->spr_dir - all->plr_dir > M_PI)
	{
		all->spr_dir -= 2 * M_PI;
	}	
	while (all->spr_dir - all->plr_dir < -M_PI)
	{
		all->spr_dir += 2 * M_PI;
	}
	all->spr_dir -= all->plr_dir;
}

int	sprites_color(t_all *all, int i, int j, int color)
{
	int		tex_w;
	int		tex_h;
	double	xf;
	double	yf;

	xf = (double)all->spr_size / all->tex_w[0];
	yf = (double)all->spr_size / all->tex_h[0];
	tex_w = (int)(i / xf);
	tex_h = (int)(j / yf);
	if (tex_h > all->tex_h[0])
		tex_h = all->tex_h[0];
	if (tex_w > all->tex_w[0])
		tex_w = all->tex_w[0];
	color = *(unsigned int *)(all->tex_addr[0] + \
	(tex_h * all->tex_line_len[0] + tex_w * (all->tex_bpp[0] / 8)));
	return (color);
}

void	sprites_draw(t_all *all, double dist, int i, int j)
{
	int	color;

	while (i < all->spr_size)
	{
		if (all->spr_x_offset + i > 0 && all->spr_x_offset + i < all->win_w \
			&& all->beam_array[(int)all->spr_x_offset + i] \
			+ 0.5 > dist)
		{
			j = 0;
			while (j < all->spr_size)
			{
				color = sprites_color(all, i, j, 0);
				if ((all->spr_y_offset + j > 0) && \
				(all->spr_y_offset + j < all->win_h)
					&& color != 0xFFFFFF)
					fast_pix_put(all, all->spr_x_offset + i, \
					all->spr_y_offset + j, color);
				j++;
			}
		}
		i++;
	}
}

void	maps_correct(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map_h)
	{
		j = 0;
		while (j < all->map_w)
		{
			if (all->map[(int)i][(int)j] == '3')
				all->map[(int)i][(int)j] = '2';
			j++;
		}
		i++;
	}
}
