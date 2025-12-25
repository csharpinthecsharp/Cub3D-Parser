/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_global_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:19:08 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 21:57:25 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	remove_line(t_map *m, t_path *p, t_color *c)
{
	free(m->db[p->loc[0]]);
	m->db[p->loc[0]] = NULL;
	free(m->db[p->loc[1]]);
	m->db[p->loc[1]] = NULL;
	free(m->db[p->loc[2]]);
	m->db[p->loc[2]] = NULL;
	free(m->db[p->loc[3]]);
	m->db[p->loc[3]] = NULL;
	free(m->db[c->loc[0]]);
	m->db[c->loc[0]] = NULL;
	free(m->db[c->loc[1]]);
	m->db[c->loc[1]] = NULL;
}

static void	push_player_position(t_parse *t, t_manip *m)
{
	t->player.x = (m->b);
	t->player.y = (m->d);
}

static void	push_line_to_db(t_parse *t, t_manip *m)
{
	while (t->map.db[m->a][m->c])
	{
		if (t->map.db[m->a][m->c] != '\n')
		{
			t->map.valid_map[m->b][m->d] = t->map.db[m->a][m->c];
			if (ft_isplayer(t->map.valid_map[m->b][m->d]))
				push_player_position(t, &t->manip);
			m->d++;
		}
		m->c++;
	}
	t->map.valid_map[m->b][m->d] = '\0';
}

static bool	filter_db(t_parse *t, t_manip *m)
{
	manip_reset(m);
	while (m->a < t->map.line_count)
	{
		if (t->map.db[m->a] != NULL)
		{
			m->count = ft_strlen(t->map.db[m->a]);
			if (t->map.db[m->a][m->count - 1] == '\n')
				m->count -= 1;
			if (t->map.db[m->a] && m->count > 0)
			{
				if (!ft_iselement(t->map.db[m->a], true, t))
					return (false);
				t->map.valid_map[m->b] = malloc(sizeof(char) * (m->count + 1));
				if (!t->map.valid_map[m->b])
					return (false);
				m->d = 0;
				m->c = 0;
				push_line_to_db(t, m);
				m->b++;
			}
		}
		m->a++;
	}
	t->map.valid_map[m->b] = NULL;
	return (true);
}

bool	validate_global_format(t_parse *t)
{
	remove_line(&t->map, &t->path, &t->color);
	t->map.height = size_for_new_db(t, &t->manip);
	if (t->map.height == 0)
		return (false);
	t->map.valid_map = malloc(sizeof(char *) * (t->map.height + 1));
	if (!t->map.valid_map)
		return (false);
	manip_reset(&t->manip);
	while (t->manip.a < t->map.height)
		t->map.valid_map[t->manip.a++] = NULL;
	if (!filter_db(t, &t->manip))
		return (false);
	if (!t->map.valid_map)
		return (false);
	return (true);
}
