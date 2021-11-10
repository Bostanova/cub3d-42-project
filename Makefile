# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 12:19:00 by eerika            #+#    #+#              #
#    Updated: 2021/05/12 14:24:56 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c initialization.c parser.c \
				checker.c draw_utils.c draw_wall_utils.c\
				draw_wall_utils2.c draw.c error.c \
				fast_pixel.c map.c move.c screen_shot.c\
				parse_floor_ceil.c parse_map.c \
				parse_resolution.c parse_textur.c\
				parser_utils.c prepare_win.c quit.c \
				$(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)
HEADERS		=	cub3d.h
NAME		=	cub3D
MLX_DIR		=	minilibx/
LIBFT_DIR	=	libft/
GNL_DIR		=	gnl/
LIBFT		=	libft.a
MLX			=	minilibx/libmlx.dylib
INCLUDES	=	-I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g -O2
MLXFLAGS	=	-framework OpenGL -framework AppKit -O2

%.o			:	%.c $(HEADERS)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX) $(OBJS)
				$(CC) $(OBJS) $(INCLUDES) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(NAME)

$(LIBFT_DIR)$(LIBFT):	$(LIBFT_DIR)
						$(MAKE) -C $(LIBFT_DIR) all

$(MLX_DIR)$(MLX):	$(MLX_DIR)			
						$(MAKE) -C $(MLX_DIR) all
clean		:
				$(RM) $(OBJS)
				$(MAKE) -C $(MLX_DIR) clean
				$(MAKE) -C $(LIBFT_DIR) clean
fclean		:	clean
				$(RM) $(NAME) 
				$(MAKE) -C $(LIBFT_DIR) fclean
re:			fclean all
