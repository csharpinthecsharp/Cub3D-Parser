/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_name_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:44 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 16:12:01 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static bool validate_name_format(const char *name)
{
    size_t len;

    len = ft_strlen(name);
    if (ft_strncmp(name + len - 4, ".cub", 5) == 0)
        return (true);
    return (false);
}

bool validate_name(const char *name)
{
    if (name)
    {
        if (!(ft_strlen(name) > 4))
        {
            ft_fperror("Map name is wrong (len is <= 4)!", STDERR_FILENO, true);
            return (false);
        }
        if (!validate_name_format(name))
        {
            ft_fperror("Map name is wrong (Missing .cub)!", STDERR_FILENO, true);
            return (false);
        }
        return (true);
    }
    ft_fperror("Wrong map format!", STDERR_FILENO, true);
    return (false);
}