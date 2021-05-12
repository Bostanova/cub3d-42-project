/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:31:23 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:38:27 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fast_pix_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	if ((x >= all->win_w) || (y >= all->win_h))
		return ;
	dst = all->img_addr + (y * all->img_line_len + x * \
	(all->img_bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	fast_pixel_take(t_all *all, int x, int y)
{
	char	*dst;

	dst = all->tex_addr[all->ray_hit_side] + \
	(y * all->tex_line_len[all->ray_hit_side] + x * \
	(all->tex_bpp[all->ray_hit_side] / 8));
	return (*(unsigned int *)dst);
}
