/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:32 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 17:25:54 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void debug(t_game *t, bool verbose)
{
    int i;

    i = 0;
    if (verbose)
    {
        printf("NORTH: %s\n", t->path.NO);
        printf("SOUTH: %s\n", t->path.SO);
        printf("EAST: %s\n", t->path.EA);
        printf("WEST: %s\n", t->path.WE);
        while (t->color.C[i] > -1)
        {
        printf("F_COLOR: %d\n", t->color.F[i]);
            i++;
        }
        i = 0;
        while (t->color.F[i] > -1)
        {
            printf("C_COLOR: %d\n", t->color.C[i]);
            i++;
        }
    }
}

bool validate_format(t_game *t)
{
    if (!validate_path_format(t))
    {
        ft_fperror("Failed to retrieve directions path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    if (!validate_color_format(t))
    {
        ft_fperror("Failed to retrieve colors in the .cub", STDERR_FILENO, true);
        return (false);
    }
    debug(t, true);
    // (1) handleDuplication Paths/Colors.
    // (2) tryOpen Paths.
    return (true);
}
