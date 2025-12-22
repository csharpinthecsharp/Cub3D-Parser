/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_open_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:49 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 17:25:57 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static bool open_map(t_game *t)
{
    t->map.fd = open(t->map.name, O_RDONLY);
    if (t->map.fd < 0)
        return (false);
    return (true);
}

static bool send_map_struct(t_game *t)
{
    char* line;
    size_t i;

    i = 0;
    line = NULL;
    if (t->map.line_count == 0)
        return (false);
    while (i < t->map.line_count)
    {
        line = get_next_line(t->map.fd);
        t->map.db[i++] = ft_strdup(line);
        free(line);
    }
    t->map.db[i] = NULL;
    clear_gnl(t->map.fd);
    close(t->map.fd);
    return (true);
}

bool validate_cub(t_game *t)
{
    if (!open_map(t))
    {
        ft_fperror("Map path not found!", STDERR_FILENO, true);
        return (false);
    }
    if (!init_map(t))
    {
        ft_fperror("Malloc failed (t->map.db)!", STDERR_FILENO, true);
        return (false);
    }
    if (!send_map_struct(t))
    {
        ft_fperror("Map is empty!", STDERR_FILENO, true);
        close(t->map.fd);
        return (false);
    }
    return (true);
}
