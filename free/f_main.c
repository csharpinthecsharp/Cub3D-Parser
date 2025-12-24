/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:16 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 16:11:51 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void free_map(t_game *t)
{
    size_t i;

    i = 0;
    free(t->map.name);
    if (t->map.db)
    {
        while (i < (t->map.line_count))
            free(t->map.db[i++]);
        free(t->map.db);
    }

    i = 0;
    if (t->map.valid_map)
    {
        while (t->map.valid_map[i])
            free(t->map.valid_map[i++]);
        free(t->map.valid_map);
    }
    return ;
}

static void free_path(t_game *t)
{
    free(t->path.NO);
    free(t->path.EA);
    free(t->path.SO);
    free(t->path.WE);
}

static void free_color(t_game *t)
{
    free(t->color.token);
    free(t->color.C);
    free(t->color.F);
}

void free_main(t_game *t)
{
    free_map(t);
    free_path(t);
    free_color(t);
    return ;
}