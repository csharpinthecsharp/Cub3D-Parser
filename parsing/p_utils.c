/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:53 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 18:21:26 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	manip_reset(t_manip *m)
{
	m->a = 0;
	m->b = 0;
	m->c = 0;
	m->d = 0;
	m->eof = false;
	m->count = 0;
}

bool	do_exist(const char *path)
{
	int	fd;

	fd = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	ft_isplayer(char c)
{
	return (c == 'S' || c == 'N' || c == 'W' || c == 'E');
}

bool	ft_iselement(char *str, bool find_for_player, t_parse *t)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!((ft_isspace(str[i]) || str[i] == '1'
					|| str[i] == '0')))
		{
			if (!ft_isplayer(str[i]))
				return (false);
			else if (find_for_player && !t->manip.eof)
			{
				t->player.direction = str[i];
				t->manip.eof = true;
			}
			else if (find_for_player && t->manip.eof)
				return (false);
		}
		i++;
	}
	return (true);
}
