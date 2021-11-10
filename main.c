/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:39:07 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 09:42:24 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	all;

	all.fd = open(argv[1], O_RDONLY);
	if (!(argc == 2 || argc == 3))
		error(-3, &all);
	check_file(argv[1], &all);
	init(&all);
	parse_file(&all);
	map(&all);
	if (argc == 3)
		check_and_screen(&all, argv[2]);
	drawing(&all);
	close(all.fd);
	return (0);
}
