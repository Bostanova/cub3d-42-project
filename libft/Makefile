# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerika <eerika@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 15:04:13 by eerika            #+#    #+#              #
#    Updated: 2021/05/11 17:37:11 by eerika           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = libft.h

SRC = ft_strlen.c ft_substr.c ft_strlcpy.c\
	ft_tolower.c ft_toupper.c ft_isprint.c\
	ft_isascii.c ft_isalnum.c ft_isdigit.c\
	ft_isalpha.c ft_atoi.c ft_bzero.c\
	ft_calloc.c ft_memccpy.c ft_memchr.c\
	ft_memcmp.c ft_memcpy.c ft_memmove.c\
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c\
	ft_strdup.c ft_strncmp.c ft_strnstr.c\
	ft_strrchr.c ft_strjoin.c ft_strtrim.c\
	ft_split.c ft_itoa.c ft_strmapi.c\
	ft_strlcat.c ft_strncmp.c \
	ft_lstnew.c ft_lstclear.c \
	ft_lstadd_back.c ft_lstlast.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(SRC) $(OBJ) $(INCLUDE)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
