/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:00:51 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:01:21 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_window(t_all *all)
{
	ft_lstclear(&all->head, 0);
	free(all->map);
	close(all->fd);
	exit(0);
}