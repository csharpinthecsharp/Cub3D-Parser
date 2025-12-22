/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:59 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 14:37:21 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main( int ac, char **av )
{
    // https://harm-smits.github.io/42docs/projects/cub3d <--- FOR RAYCASTING
    (void)av;
    t_game game;
    t_game *t;
    t = &game;
    if (ac != 2)
    {
        ft_fperror("Expected 1 argument (*.cub)!", STDERR_FILENO, true);
        return (1);
    }
    if (!parsing_main(t, av[1]))
    {
        free_main(t);
        return (1);
    }
    free_main(t);
    return (0);
}