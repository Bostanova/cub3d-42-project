/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:17:09 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:35:28 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_header_info(unsigned char *header, int number, int bit)
{
	int	i;

	i = 0;
	while (i < bit)
	{
		header[i] = (unsigned char)(number >> (i * 8));
		i++;
	}
}

static void	ft_set_header(int fd, t_all *all)
{
	int				i;
	int				filesize;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = '\0';
	filesize = 54 + (4 * all->win_w * all->win_h);
	header[0] = (unsigned char) 'B';
	header[1] = (unsigned char) 'M';
	ft_set_header_info(header + 2, filesize, 4);
	ft_set_header_info(header + 10, 54, 4);
	ft_set_header_info(header + 14, 40, 4);
	ft_set_header_info(header + 18, all->win_w, 4);
	ft_set_header_info(header + 22, all->win_h, 4);
	ft_set_header_info(header + 26, 1, 2);
	ft_set_header_info(header + 28, 24, 2);
	write(fd, header, 54);
}

static void	ft_set_image(int fd, t_all *all)
{
	int		i;
	int		j;
	int		color;
	char	*color_dst;

	i = all->win_h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->win_w)
		{
			color_dst = all->img_addr + \
			(i * all->img_line_len + j * (all->img_bpp / 8));
			color = *(unsigned int *)color_dst;
			write(fd, &color, 3);
			j++;
		}
		i--;
	}
}

void	screen_shot(t_all *all)
{
	int	fd;

	fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	if (fd == -1)
		error(-2, all);
	ft_set_header(fd, all);
	ft_set_image(fd, all);
	close(fd);
}

void	check_and_screen(t_all *all, char *s)
{
	if ((ft_strncmp(s, "--save", 6)) == 0 && ft_strlen(s) == 6)
	{
		all->bmp = 1;
		create_window(all);
		draw_floor_ceil(all);
		draw_wall(all, 0, all->plr_dir - (M_PI_2 / 3), 0);
		draw_sprite(all);
		screen_shot(all);
	}
	else
		error(-3, all);
	exit(0);
}
