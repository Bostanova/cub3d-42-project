/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:09:19 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:36:40 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_line(char *l, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (l[j])
	{
		if (l[j] == ',')
		{
			l[j] = ' ';
			i++;
		}
		j++;
	}
	if (i != 2)
		error(-12, all);
	return (l);
}

void	floor_ceil(char *l, int *dist, t_all *all, t_check *opt)
{
	int		r;
	int		g;
	int		b;
	char	**list;

	l = check_line(l, all);
	if ((l[0] == 'C' && opt->c == 1) || (l[0] == 'F' && opt->f == 1))
		error(-11, all);
	list = ft_split(l, ' ');
	if ((num_words(list)) != 4)
		error(-12, all);
	r = is_num(list[1]);
	g = is_num(list[2]);
	b = is_num(list[3]);
	if (r < 0 || r >255 || g < 0 || g > 255 || b < 0 || b > 255)
		error(-12, all);
	*dist = create_trgb(0, r, g, b);
	if (l[0] == 'F')
		opt->f = 1;
	else if (l[0] == 'C')
		opt->c = 1;
	clean(list);
}
