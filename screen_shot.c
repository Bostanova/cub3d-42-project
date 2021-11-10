/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:17:09 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 14:08:21 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_screen(t_all *all, char *s)
{
	if ((ft_strncmp(s, "--save", 6)) == 0 && ft_strlen(s) == 6)
	{
		all->bmp = 1;
		create_window(all);
		draw_floor_ceil(all);
		draw_wall(all, 0, all->plr_dir - (M_PI_2 / 3), 0);
		draw_sprite(all);
		save_bmp(all);
	}
	else
		error(-3, all);
	exit(0);
}

void	bitmap_info(unsigned char *map, int nbr, int bit)
{
	int	i;

	i = 0;
	while (i < bit)
	{
		map[i] = (unsigned char)(nbr >> (i * 8));
		i++;
	}
}

void	make_bitmap(int fd, t_all *all)
{
	int				i;
	int				size;
	unsigned char	map[54];

	i = 0;
	while (i < 54)
		map[i++] = '\0';
	size = 54 + (4 * all->win_w * all->win_h);
	map[0] = (unsigned char) 'B';
	map[1] = (unsigned char) 'M';
	bitmap_info(map + 2, size, 4);
	bitmap_info(map + 10, 54, 4);
	bitmap_info(map + 14, 40, 4);
	bitmap_info(map + 18, all->win_w, 4);
	bitmap_info(map + 22, all->win_h, 4);
	bitmap_info(map + 26, 1, 2);
	bitmap_info(map + 28, 24, 2);
	write(fd, map, 54);
}

void	make_image(int fd, t_all *all)
{
	int		i;
	int		j;
	int		color;

	i = all->win_h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->win_w)
		{
			color = *(unsigned int *)(all->img_addr + \
			(i * all->img_line_len + j * (all->img_bpp / 8)));
			write(fd, &color, 3);
			j++;
		}
		i--;
	}
}

void	save_bmp(t_all *all)
{
	int	fd;

	fd = open("scr.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	if (fd == -1)
		error(-2, all);
	make_bitmap(fd, all);
	make_image(fd, all);
	close(fd);
}
