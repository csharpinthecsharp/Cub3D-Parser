/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_path_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:20:46 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 22:21:26 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char	*retrieve_path(char *request, char *token, t_parse *t)
{
	manip_reset(&t->manip);
	while (t->manip.a < t->map.line_count)
	{
		if (t->manip.eof)
			break ;
		t->manip.b = 0;
		while (t->map.db[t->manip.a][t->manip.b])
		{
			if (t->manip.eof && !ft_isspace(t->map.db[t->manip.a][t->manip.b]))
				token[t->manip.c++] = t->map.db[t->manip.a][t->manip.b];
			if ((t->map.db[t->manip.a][t->manip.b] == request[0])
				&& (t->map.db[t->manip.a][t->manip.b + 1] == request[1]))
			{
				t->manip.eof = true;
				t->manip.b++;
			}
			t->manip.b++;
		}
		t->manip.a++;
	}
	token[t->manip.c++] = '\0';
	if (!ft_strlen(token))
		return (free(token), NULL);
	return (token);
}

bool	validate_path_format(t_parse *t)
{
	if (!init_path(t))
		return (false);
	t->path.no = retrieve_path("NO", t->path.no, t);
	if (!t->path.no || !do_exist(t->path.no))
		return (false);
	t->path.so = retrieve_path("SO", t->path.so, t);
	if (!t->path.so || !do_exist(t->path.so))
		return (false);
	t->path.we = retrieve_path("WE", t->path.we, t);
	if (!t->path.we || !do_exist(t->path.we))
		return (false);
	t->path.ea = retrieve_path("EA", t->path.ea, t);
	if (!t->path.ea || !do_exist(t->path.ea))
		return (false);
	return (true);
}
