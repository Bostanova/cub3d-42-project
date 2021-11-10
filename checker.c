/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:04:37 by eerika            #+#    #+#             */
/*   Updated: 2021/05/11 18:05:12 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file(char *s, t_all *all)
{
	if ((ft_strncmp(&s[ft_strlen(s) - 4], ".cub", 4))
		|| ft_strlen(s) == 4)
		error(-1, all);
}

void	check_options(t_check *check, t_all *all)
{
	int	count;

	count = check->dir + check->so \
	+ check->no + check->ea + check->we \
	+ check->s + check->c + check->f + check->r;
	if (count < 9)
		error(-8, all);
}
