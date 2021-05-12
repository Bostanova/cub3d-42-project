/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:00:18 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:39:55 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_helper(int error, t_all *all)
{
	if (error == -7)
		write(2, "Error:\nCouldn't create window\n", 30);
	if (error == -8)
		write(2, "Error:\nDoesn't texture enough\n", 30);
	if (error == -9)
		write(2, "Error:\nResolution specified twice\n", 34);
	if (error == -10)
		write(2, "Error:\nInvalid resolution\n", 26);
	if (error == -11)
		write(2, "Error:\nTexture path specified twice\n", 36);
	if (error == -12)
		write(2, "Error:\nInvalid floor/ceiling line\n", 34);
	ft_lstclear(&all->head, 0);
	close(all->fd);
	exit(1);
}

void	error(int error, t_all *all)
{
	if (error <= -7)
		error_helper(error, all);
	if (error == -1)
		write(2, "Error:\nInvalid extension\n", 25);
	if (error == -2)
		write(2, "Error:\nCouldn't open file\n", 26);
	if (error == -3)
		write(2, "Error:\nInvalid arguments\n", 25);
	if (error == -4)
		write(2, "Error:\nMalloc fail\n", 19);
	if (error == -5)
		write(2, "Error:\nInvalid map\n", 19);
	if (error == -6)
		write(2, "Error:\nInvalid texture(path)\n", 29);
	ft_lstclear(&all->head, 0);
	close(all->fd);
	exit(1);
}
