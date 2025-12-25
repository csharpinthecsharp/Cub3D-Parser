/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_global_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:19:08 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 02:25:14 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	remove_line(t_map *m, t_loc *t)
{
	free(m->db[t->so]);
	m->db[t->so] = NULL;
	free(m->db[t->no]);
	m->db[t->no] = NULL;
	free(m->db[t->ea]);
	m->db[t->ea] = NULL;
	free(m->db[t->we]);
	m->db[t->we] = NULL;
	free(m->db[t->f]);
	m->db[t->f] = NULL;
	free(m->db[t->c]);
	m->db[t->c] = NULL;
}

static void	push_player_position(t_parse *t, t_manip *m)
{
	t->player.x = (m->b);
	t->player.y = (m->d);
}

static void	push_line_to_db(t_parse *t, t_manip *m)
{
	while (t->map.db[m->a][m->c++])
	{
		if (t->map.db[m->a][m->c] != '\n')
		{
			while (ft_isspace(t->map.db[m->a][m->c]))
				m->c++;
			t->map.valid_map[m->b][m->d++] = t->map.db[m->a][m->c];
			if (ft_isplayer(t->map.valid_map[m->b][m->d - 1]))
				push_player_position(t, &t->manip);
		}
	}
}

static bool	filter_db(t_parse *t, t_manip *m)
{
	manip_reset(t);
	while (m->a < t->map.line_count)
	{
		if (t->map.db[m->a] != NULL)
		{
			m->count = ft_strlen(t->map.db[m->a]);
			if (t->map.db[m->a] && m->count > 2)
			{
				if (!ft_iselement(t->map.db[m->a], true, t))
					return (false);
				m->count--;
				t->map.valid_map[m->b] = malloc(sizeof(char) * (m->count + 1));
				if (!t->map.valid_map[m->b])
					return (false);
				m->d = 0;
				m->c = 0;
				push_line_to_db(t, m);
				t->map.valid_map[m->b][m->d] = '\0';
				m->b++;
			}
		}
		m->a++;
	}
	return (t->map.valid_map[m->b] = NULL, true);
}

bool	validate_global_format(t_parse *t)
{
	size_t	len;

	(void)len;
	remove_line(&t->map, &t->loc);
	len = size_for_new_db(t, &t->manip);
	if (len == 0)
		return (false);
	t->map.valid_map = malloc(sizeof(char *) * (len + 1));
	if (!t->map.valid_map)
		return (false);
	if (!filter_db(t, &t->manip))
		return (false);
	if (!t->map.valid_map)
		return (false);
	return (true);
}
