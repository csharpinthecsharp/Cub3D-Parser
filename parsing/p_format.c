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

bool validate_format(t_game *t)
{
    if (!validate_path_format(t))
    {
        ft_fperror("The colors format was not accepted.", STDERR_FILENO, true);
        return (false);
    }
    if (!validate_color_format(t))
    {
        ft_fperror("The paths format was not accepted.", STDERR_FILENO, true);
        return (false);
    }
    if (!validate_global_format(t))
    {
        ft_fperror("The global format was not accepted.", STDERR_FILENO, true);
        return (false);
    }
    if (!validate_map_format(t))
    {
        ft_fperror("The map format was not accepted.", STDERR_FILENO, true);
        return (false);
    }
    // (1) handleDuplication Paths/Colors.
    return (true);
}
