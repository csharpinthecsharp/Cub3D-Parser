/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:53 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/22 14:22:55 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void manip_reset(t_game *t)
{
    t->manip.a = 0;
    t->manip.b = 0;
    t->manip.c = 0;
    t->manip.d = 0;
    t->manip.eof = false;
    t->manip.count = 0;
}

bool do_exist(const char *path)
{
    int fd = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (false);
    close(fd);
    return (true);
}

bool ft_iselement(char *str)
{
    size_t i = 0;

    while (str[i])
    {
        if (!(ft_isspace(str[i]) || str[i] == '1' || 
              str[i] == '0' || str[i] == 'S' || str[i] == 'N' ||
              str[i] == 'W' || str[i] == 'E' || str[i] == '\n'))
            return false;
        i++;
    }
    return true;
}
