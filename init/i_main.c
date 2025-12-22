/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:13 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 17:26:02 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool init_map(t_game *t)
{
    t->map.line_count = size_for_line_count(t->map.name);
    t->map.db = malloc(sizeof(char *) * (t->map.line_count + 1));
    if (!t->map.db)
    {
        close(t->map.fd);
        return (false);
    }
    return (true);
}

bool init_path(t_game *t)
{
    size_t size_NO = size_for_path("NO", t);
    size_t size_EA = size_for_path("EA", t);
    size_t size_SO = size_for_path("SO", t);
    size_t size_WE = size_for_path("WE", t);
    t->path.NO = malloc(sizeof(char) * (size_NO + 1));
    if (!t->path.NO)
        return (false);
    t->path.EA = malloc(sizeof(char) * (size_EA + 1));
    if (!t->path.EA)
        return (false);
    t->path.SO = malloc(sizeof(char) * (size_SO + 1));
    if (!t->path.SO)
        return (false);
    t->path.WE = malloc(sizeof(char) * (size_WE + 1));
    if (!t->path.SO)
        return (false);
    return (true);
}

bool init_color(t_game *t, char type)
{
    size_t len;

    if (type == 'F')
        len = size_for_color_token('F', t);
    else
        len = size_for_color_token('C', t);
    t->color.token = malloc(sizeof(char) * (len + 1));
    if (!t->color.token)
        return (false);
    if (type == 'F')
    {
        t->color.token = retrieve_color('F', t->color.token, t);
        t->color.F = ft_calloc(MAX_LEN_RGB + 1, sizeof(int));
        t->color.F[MAX_LEN_RGB] = -1;  
    }
    else
    {
        t->color.token = retrieve_color('C', t->color.token, t);
        t->color.C = ft_calloc(MAX_LEN_RGB + 1, sizeof(int));
        t->color.C[MAX_LEN_RGB] = -1;
    }
    if (type == 'C')
        free(t->color.token);
}

void init_main(t_game *t, const char *map_name)
{
    t->map.name = ft_strdup(map_name);
    t->map.name_len = ft_strlen(map_name);
    t->map.db = NULL;
    t->map.fd = -1;
    t->map.line_count = 0;
    t->manip.a = 0;
    t->manip.b = 0;
    t->manip.c = 0;
    t->manip.eof = false;
    t->manip.count = 0;
    t->path.NO = NULL;
    t->path.EA = NULL;
    t->path.SO = NULL;
    t->path.WE = NULL;
    t->color.token = NULL;
    t->color.C = NULL;
    t->color.F = NULL;
    return ;
}
