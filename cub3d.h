/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:38:42 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 13:28:44 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "get_next_line.h"
# include "libft.h"

# define MAP " 012NWES"
# define DIR "NWES"

typedef struct s_check
{
	int		dir;
	int		so;
	int		no;
	int		ea;
	int		we;
	int		s;
	int		c;
	int		f;
	int		r;
}				t_check;

typedef struct s_all
{
	char	dir;
	char	**map;
	char	*so;
	char	*no;
	char	*ea;
	char	*we;
	char	*spr_tex;
	int		sprites;
	int		ceil_colour;
	int		floor_colour;
	int		is_map_flag;
	int		win_w;
	int		win_h;
	int		fd;
	int		gnl;
	int		map_w;
	int		map_h;
	double	posX;
	double	posY;
	t_list	*head;
	void	*mlx;
	void	*mlx_win;
	void	*img_img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_len;
	int		img_endian;

	char	**tex_path;
	void	**tex_mlx;
	void	**tex_img;
	char	**tex_addr;
	int		*tex_h;
	int		*tex_w;
	int		*tex_bpp;
	int		*tex_line_len;
	int		*tex_endian;

	int		scr_w;
	int		scr_h;
	int		bmp;

	int		spr_x;
	int		spr_y;
	int		spr_size;
	double	spr_dir;
	int		spr_x_offset;
	int		spr_y_offset;
	double	*array_col;

	double	wall_h;
	double	vert_obst;
	double	hor_obst;
	double	angle;
	int		ray_vX;
	double	ray_vY;
	double	ray_hX;
	int		ray_hY;
	double	begin;
	double	end;
	double	plr_dir;
	double	ray_step;
	double	proj_plane;
	double	ray_pos_x;
	double	ray_pos_y;
	int		ray_hit_side;
	double	x_offset;
	double	y_offset;
}				t_all;

int				main(int argc, char **argv);
void			check_file(char *s, t_all *all);
void			check_options(t_check *check, t_all *all);
double			dist_to_sprite(t_all *all, double dist, int x, int y);
void			sprite_dir(t_all *all);
int				sprites_color(t_all *all, int i, int j, int color);
void			sprites_draw(t_all *all, double dist, int i, int j);
void			maps_correct(t_all *all);
double			dist_to_wall(t_all *all, double begin);
void			check_wall(t_all *all);
double			get_dist_y(t_all *all, double tex_st);
void			offset_y(t_all *all);
double			check_dist_y(t_all *all, double dsy, double tex_st);
double			vert_obstacle(t_all *all, double Y, int X, double ray);
double			hor_obstacle(t_all *all, double X, int Y, double ray);
void			offset_x(double vert_obst, double hor_obst, t_all *all);
void			hits_side(double vert_obst, double hor_obst, t_all *all);
void			draw_floor_ceil(t_all *all);
void			draw_wall(t_all *s, int col, double begin, double ray_len);
void			draw_sprite(t_all *all);
void			draw_n_synx(t_all *all);
void			drawing(t_all *all);
void			step_up(t_all *all, double c, double s);
void			step_back(t_all *all, double c, double s);
void			step_left(t_all *all, double c, double s);
void			step_right(t_all *all, double c, double s);
int				key_press(int key, t_all *all);
void			error_helper(int error, t_all *all);
void			error(int error, t_all *all);
int				create_trgb(int t, int r, int g, int b);
void			fast_pix_put(t_all *all, int x, int y, int color);
unsigned int	fast_pixel_take(t_all *all, int x, int y);
void			init(t_all *all);
void			init_check(t_check *check);
void			init_player(t_all *all);
void			init_texture(t_all *all);
void			fill_line(t_all *all, void **content);
void			check_unit(t_all *all, int x, int y);
void			check_map(t_all *all);
void			map(t_all *all);
char			*check_line(char *l, t_all *all);
void			floor_ceil(char *l, int *dist, t_all *all, t_check *opt);
void			map_parse(char *line, t_all *all, t_check *check, int i);
void			resolution(char *line, t_all *all, t_check *check);
void			texture(char *line, char **path, t_all *all, t_check *check);
int				num_words(char **list);
void			clean(char **list);
void			set_checking(t_check *check, char *line);
int				is_num(char *list);
void			parse_texture(char *line, t_all *all, t_check *check);
void			parse_file(t_all *all);
void			alloc_for_tex(t_all *all);
void			alloc_for_tex_helper (t_all *all);
void			get_info_tex(t_all *all);
void			check_screen_size(t_all *all);
void			create_window(t_all *all);
int				exit_window(t_all *all);
void			bitmap_info(unsigned char *map, int nbr, int bit);
void			make_bitmap(int fd, t_all *all);
void			make_image(int fd, t_all *all);
void			save_bmp(t_all *all);
void			check_and_screen(t_all *all, char *s);

#endif