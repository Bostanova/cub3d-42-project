/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:38:42 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:56:52 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "minilibx/mlx.h"

# define MAP " 012NWES" //допустимые символы на карте
# define DIR "NWES" //символ на карте, определяющий начальное направление игрока

typedef struct	s_all
{
	char	dir; //взгляд игрока = N, W, S or E
	char	**map; //двумерный массив, содержит карту, перезаписан со связного списка с дополнением некоторых строк пробелами при необходимости
	char	*so; //путь к файлу с текстурой, берем из файла .cub
	char	*no; // то же
	char	*ea; // то же
	char	*we; // то же
	char	*spr_tex; // то же, путь к файлу с тектурой для спрайта
	int		sprites; // количество спрайтов, считан с файла .cub
	int		ceil_colour; //цвет потолка, считан с файла .cub
	int		floor_colour; //also
	int		is_map_flag;
	int		win_w; //ширина экрана, считанная с файла .cub
	int		win_h; //высота экрана, считанная с файла .cub
	int		fd;
	int		gnl; //считывает файл .cub
	int		map_w; // ширина карты
	int		map_h; //высота карты, считывается с .cub построчно с помощью gnl
	double	posX;  //начальная позиция игрока (N, S, W, or E from .cub) //в дальнейшем смещение на 0,5
	double	posY; //also //also
	t_list	*head; //начало связного списка, хранит строки карты
	void	*mlx;
	void	*mlx_win;

	int		scr_w; //ширина экрана компа, получена через mlxlib
	int		scr_h; //высота экрана компа, получена через mlxlib
	int		bmp; //ставим =1, если есть аргумент --save

	int		spr_x;
	int		spr_y;
	int		spr_size;
	double	spr_dir;
	int		spr_x_offset;
	int		spr_y_offset;
	double	*beam_array; //массив размера (map_w + 1) на win_w

	double	wall_h; //proj_plane, деленное на длину луча до стены
	double	vert_obst;
	double	hor_obst;
	double	angle;
	int		v_dX; // координата точки направления луча = +/-1
	double	v_dY; //
	double	h_dX; //
	int		h_dY; //

	void	*img_img; //указатель на первый созданный экран
	char	*img_addr; //нужен для получения инфы, см ниже
	int		img_bpp; // инфа о bits_per_pixel
	int		img_line_len; // длина строки изображения
	int		img_endian; //

	double	end;
	double	plr_dir; //направление игрока в соответствии с dir
	double	start;
	double	ray_step; // угол - расстоиние между лучами fov / win_w  (60 градусов делим на win_w)
	double	proj_plane; // размер окна в точках win_w / 2 / tan(M_PI_2 / 3)

	double	ray_pos_x; //координата точки прикосновения луча к стене (для рисования стены)
	double	ray_pos_y;
	int		ray_hit_side; // сторона удара 1,2,3 или 4
	double	x_offset; // смещение луча
	double	y_offset;

// каждый массив состоит из пяти элементов
	char	**tex_path; //массив из 5 текстур - спрайт и стены (хранит пути из *no, *so ...)
	void	**tex_mlx; // массив из 5 указателей из mlx_init (по одной для каждой текстуры)
	void	**tex_img; //also with img
	char	**tex_addr; // то же - получаем инфу о пяти img
	int		*tex_h; // also получила инфу о высоте текстуры
	int		*tex_w; // also получила инфу о ширине текстуры
	int		*tex_bpp; //заполняется из tex_addr
	int		*tex_line_len; //also
	int		*tex_endian; //also
}				t_all;

typedef struct s_check
{
	int		dir; //если =0, то направление игрока не считано и не установлено
	int		so;     // если =0, то текстура еще не установлена в parsinfo
	int		no; // то же или 0, или 1
	int		ea; // то же
	int		we; // то же
	int		s; // то же
	int		c; // если =0, то цвет потолка не установлен; 1 - установлен
	int		f; // то же
	int		r;  // если =1, то расширение экрана установлено в структуру t_all
}				t_check;

int				main(int argc, char **argv);
void			check_file(char *s, t_all *all);
void			check_options(t_check *check, t_all *all);
double			dist_to_sprite(t_all *all, double dist, int x, int y);
void			sprite_dir(t_all *all);
int				sprites_color(t_all *all, int i, int j, int color);
void			sprites_draw(t_all *all, double dist, int i, int j);
void			maps_correct(t_all *all);
double			dist_to_wall(t_all *all, double start);
void			check_wall(t_all *all);
double			get_dy(t_all *all, double tex_st);
void			offset_y(t_all *all);
double			check_dy(t_all *all, double dy, double tex_st);
double			vert_obstacle(t_all *all, double nearY, int nearX, double ray);
double			hor_obstacle(t_all *all, double nearX, int nearY, double ray);
void			offset_x(double vert_obst, double hor_obst, t_all *all);
void			hits_side(double vert_obst, double hor_obst, t_all *all);
void			draw_floor_ceil(t_all *all);
void			draw_wall(t_all *s, int col, double start, double len_ray);
void			draw_sprite(t_all *all);
void			draw_n_synx(t_all *all);
void			drawing(t_all *all);
void			change_w(t_all *all, double c, double s);
void			change_s(t_all *all, double c, double s);
void			change_a(t_all *all, double c, double s);
void			change_d(t_all *all, double c, double s);
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
void			screen_shot(t_all *all);
void			check_and_screen(t_all *all, char *s);


#endif