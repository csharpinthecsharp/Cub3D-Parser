/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alloc_sizes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:02 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 17:26:06 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

size_t size_for_path(char *request, t_game *t)
{
    manip_reset(t);
    while (t->manip.a < t->map.line_count)
    {
        if (t->manip.eof)
            break;
        t->manip.b = 0;
        while (t->map.db[t->manip.a][t->manip.b])
        {
            if (t->manip.eof && (t->map.db[t->manip.a][t->manip.b] != ' '))
                t->manip.count++;
            if ((t->map.db[t->manip.a][t->manip.b] == request[0]) &&
                    (t->map.db[t->manip.a][t->manip.b + 1] == request[1]))
            {
                t->loc.current = t->manip.a;
                t->manip.eof = true;
                t->manip.b++;
            }
            t->manip.b++;
        }
        t->manip.a++;
    }
    return (t->manip.count);
}

size_t size_for_color_token(char request, t_game *t)
{
    manip_reset(t);
    while (t->manip.a < t->map.line_count)
    {
        if (t->manip.eof)
            break;
        t->manip.b = 0;
        while (t->map.db[t->manip.a][t->manip.b])
        {
            if (t->manip.eof && (t->map.db[t->manip.a][t->manip.b] != ' '))
                t->manip.count++;
            if (t->map.db[t->manip.a][t->manip.b] == request)
            {
                t->loc.current = t->manip.a;
                t->manip.eof = true;
                t->manip.b++;
            }
            t->manip.b++;
        }
        t->manip.a++;
    }
    return (t->manip.count);
}

size_t size_for_line_count(const char *name)
{
    size_t count;
    char *line;
    int fd;

    count = 0;
    line = NULL;
    fd = open(name, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        count++;
    }
    close(fd);
    return (count);
}