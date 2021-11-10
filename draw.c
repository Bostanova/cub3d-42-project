/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:19:31 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 12:26:02 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceil(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y++ < all->win_h / 2)
	{
		x = 0;
		while (x++ < all->win_w)
			fast_pix_put(all, x, y, all->ceil_colour);
	}
	while (y++ < all->win_h)
	{
		x = 0;
		while (x++ < all->win_w)
			fast_pix_put(all, x, y, all->floor_colour);
	}
}

void	draw_wall(t_all *s, int col, double begin, double ray_len)
{
	int		y;
	int		dsx;
	double	dsy;
	double	tex_st;

	while (col < s->win_w)
	{
		ray_len = dist_to_wall(s, begin);
		s->wall_h = (int)(s->proj_plane / ray_len);
		offset_y(s);
		tex_st = (double)s->tex_h[s->ray_hit_side] / s->wall_h;
		check_wall(s);
		dsx = s->tex_w[s->ray_hit_side] * s->x_offset;
		dsy = get_dist_y(s, tex_st);
		y = -1 * s->wall_h / 2;
		while (y < s->wall_h / 2)
		{
			fast_pix_put(s, col, s->win_h /2 +y, fast_pixel_take(s, dsx, dsy));
			dsy = check_dist_y(s, dsy, tex_st);
			y++;
		}
		s->array_col[col] = ray_len;
		begin += s->ray_step;
		col++;
	}
}

void	draw_sprite(t_all *all)
{
	int		i;
	double	dist;

	i = 0;
	while (i < all->sprites)
	{
		dist = dist_to_sprite(all, 0, 0, 0);
		sprite_dir(all);
		all->spr_size = (int)((double)all->proj_plane / dist);
		all->spr_x_offset = all->win_w / 2 - 1 + tan(all->spr_dir) * \
		all->proj_plane - all->spr_size / 2;
		all->spr_y_offset = all->win_h / 2 - all->spr_size / 2;
		if (fabs(all->spr_dir) < M_PI_2)
			sprites_draw(all, dist, 0, 0);
		i++;
	}
	maps_correct(all);
}

void	draw_n_synx(t_all *all)
{
	draw_floor_ceil(all);
	draw_wall(all, 0, all->plr_dir - (M_PI_2 / 3), 0);
	draw_sprite(all);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img_img, 0, 0);
	mlx_do_sync(all->mlx);
}

void	drawing(t_all *all)
{
	create_window(all);
	all->mlx_win = mlx_new_window(all->mlx, all->win_w, \
		all->win_h, "cub3D");
	if (!all->mlx_win)
		error(-7, all);
	draw_n_synx(all);
	mlx_hook(all->mlx_win, 2, (1L << 0), &key_press, all);
	mlx_hook(all->mlx_win, 17, (1L << 0), &exit_window, all);
	mlx_loop(all->mlx);
}
