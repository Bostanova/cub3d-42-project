/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:25:54 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:52:36 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	alloc_for_tex_helper (t_all *all)
{
	all->tex_h = ft_calloc(5, sizeof (int));
	if (!all->tex_h)
		error(-4, all);
	all->tex_w = ft_calloc(5, sizeof (int));
	if (!all->tex_w)
		error(-4, all);
	all->tex_bpp = ft_calloc(5, sizeof (int));
	if (!all->tex_bpp)
		error(-4, all);
	all->tex_line_len = ft_calloc(5, sizeof (int));
	if (!all->tex_line_len)
		error(-4, all);
	all->tex_endian = ft_calloc(5, sizeof (int));
	if (!all->tex_endian)
		error(-4, all);
}

void	alloc_for_tex(t_all *all)
{
	all->tex_mlx = ft_calloc(5, sizeof (void *));
	if (!all->tex_mlx)
		error(-4, all);
	all->tex_path = ft_calloc(5, sizeof (char *));
	if (!all->tex_path)
		error(-4, all);
	all->tex_img = ft_calloc(5, sizeof (void *));
	if (!all->tex_img)
		error(-4, all);
	all->tex_addr = ft_calloc(5, sizeof (char *));
	if (!all->tex_addr)
		error(-4, all);
	alloc_for_tex_helper(all);
}

void	get_info_tex(t_all *all)
{
	int		i;

	alloc_for_tex(all);
	init_texture(all);
	i = 0;
	while (i < 5)
	{
		all->tex_mlx[i] = mlx_init();
		if (!(all->tex_mlx[i]))
			error(-6, all);
		all->tex_img[i] = mlx_xpm_file_to_image(all->tex_mlx[i], all->tex_path[i], \
		&all->tex_w[i], &all->tex_h[i]);
		if (!(all->tex_img[i]))
			error(-6, all);
		all->tex_addr[i] = mlx_get_data_addr(all->tex_img[i], &all->tex_bpp[i], \
		&all->tex_line_len[i], &all->tex_endian[i]);
		if (!(all->tex_addr[i]))
			error(-6, all);
		i++;
	}
}

void	check_screen_size(t_all *all)
{
	mlx_get_screen_size(all->mlx, &all->scr_w, &all->scr_h);
	if (all->bmp == 0)
	{			
		if (all->win_w > all->scr_w)
			all->win_w = all->scr_w;
		if (all->win_h > all->scr_h)
			all->win_h = all->scr_h;
	}
}

void	create_window(t_all *all)
{
	init_player(all);
	all->mlx = mlx_init();
	check_screen_size(all);
	all->img_img = mlx_new_image(all->mlx, all->win_w, all->win_h);
	all->img_addr = mlx_get_data_addr(all->img_img, &all->img_bpp, \
		&all->img_line_len, &all->img_endian);
	if (!all->mlx || !all->img_img || !all->img_addr)
		error(-7, all);
	get_info_tex(all);
}
