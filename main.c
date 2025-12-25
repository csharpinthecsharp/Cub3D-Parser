/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:59 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 23:14:40 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	main(int ac, char **av)
{
	t_parse	par;
	t_parse	*t;

	t = &par;
	if (ac != 2)
	{
		ft_puterror("Expected 1 argument (*.cub)!");
		return (1);
	}
	if (!parsing_main(t, av[1]))
	{
		ft_puterror("Parsing failed, exiting!");
		free_parsing(t);
		return (1);
	}
	ft_putgood("Parsing succeeded, starting!");
	free_parsing(t);
	return (0);
}
