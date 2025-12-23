/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_entry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:07 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 16:11:57 by ltrillar         ###   ########.fr       */
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

bool parsing_main(t_game *t, const char *name)
{
    init_main(t, name);
    if (!validate_name(name))
        return (false);
    if (!validate_cub(t))
        return (false);
    if (!validate_format(t))
        return (false);
    debug(t, true);
    return (true);
}
