/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:59 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 14:33:00 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	debug(t_parse *t, bool verbose)
{
	size_t	i;

	i = 0;
	if (verbose)
	{
		printf("NORTH: %s\n", t->path.no);
		printf("SOUTH: %s\n", t->path.so);
		printf("EAST: %s\n", t->path.ea);
		printf("WEST: %s\n", t->path.we);
		while (t->color.c[i] > -1)
		{
			printf("F_COLOR: %d\n", t->color.f[i]);
			i++;
		}
		i = 0;
		while (t->color.f[i] > -1)
		{
			printf("C_COLOR: %d\n", t->color.c[i]);
			i++;
		}
		i = 0;
		while (t->map.valid_map[i])
		{
			printf("%s\n", t->map.valid_map[i]);
			i++;
		}
		printf("P_DIRECTION: %c\n", t->player.direction);
		printf("P_X: %d\n", t->player.x);
		printf("P_Y: %d\n", t->player.y);
	}
}

int	main(int ac, char **av)
{
	t_parse	par;
	t_parse	*t;

	t = &par;
	if (ac != 2)
	{
		ft_fperror("Expected 1 argument (*.cub)!", STDERR_FILENO, true);
		return (1);
	}
	if (!parsing_main(t, av[1]))
	{
		free_parsing(t);
		return (1);
	}
	debug(t, true);
	free_parsing(t);
	return (0);
}
