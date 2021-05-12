/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:05:36 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:36:01 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	num_words(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

void	clean(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	set_checking(t_check *check, char *line)
{
	if (line[0] == 'S' && line[1] == 'O')
		check->so = 1;
	else if (line[0] == 'N')
		check->no = 1;
	else if (line[0] == 'S' && line[1] == ' ')
		check->s = 1;
	else if (line[0] == 'W')
		check->we = 1;
	else if (line[0] == 'E')
		check->ea = 1;
}

int	is_num(char *list)
{
	int	i;
	int	num;

	i = 0;
	num = -1;
	while (list[i])
	{
		if (!ft_isdigit(list[i]))
			return (num);
		i++;
	}
	num = ft_atoi(list);
	return (num);
}
