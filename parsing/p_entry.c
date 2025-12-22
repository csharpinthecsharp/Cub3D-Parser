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

bool parsing_main(t_game *t, const char *name)
{
    init_main(t, name);
    if (!validate_name(name))
        return (false);
    if (!validate_cub(t))
        return (false);
    if (!validate_format(t))
        return (false);
    return (true);
}