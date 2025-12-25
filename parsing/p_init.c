/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:13 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 02:04:19 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool	init_map(t_parse *t)
{
	t->map.line_count = size_for_line_count(t->map.name);
	t->map.db = malloc(sizeof(char *) * (t->map.line_count + 1));
	if (!t->map.db)
	{
		close(t->map.fd);
		return (false);
	}
	return (true);
}

bool	init_path(t_parse *t)
{
	t->path.no = malloc(sizeof(char) * (size_for_path("NO", t) + 1));
	if (!t->path.no)
		return (false);
	t->loc.no = t->loc.current;
	t->path.ea = malloc(sizeof(char) * (size_for_path("EA", t) + 1));
	if (!t->path.ea)
		return (false);
	t->loc.ea = t->loc.current;
	t->path.so = malloc(sizeof(char) * (size_for_path("SO", t) + 1));
	if (!t->path.so)
		return (false);
	t->loc.so = t->loc.current;
	t->path.we = malloc(sizeof(char) * (size_for_path("WE", t) + 1));
	if (!t->path.we)
		return (false);
	t->loc.we = t->loc.current;
	return (true);
}

bool	init_color(t_parse *t, char type)
{
	size_t	len;
	int		**clr_ptr;
	size_t	*loc_ptr;

	if (type == 'F')
	{
		clr_ptr = &t->color.f;
		loc_ptr = &t->loc.f;
	}
	else
	{
		free(t->color.token);
		clr_ptr = &t->color.c;
		loc_ptr = &t->loc.c;
	}
	len = size_for_color_token(type, t);
	*loc_ptr = t->loc.current;
	t->color.token = malloc(sizeof(char) * (len + 1));
	if (!t->color.token)
		return (false);
	t->color.token = retrieve_color(type, t->color.token, t);
	if (!t->color.token)
		return (false);
	*clr_ptr = ft_calloc(3 + 1, sizeof(int));
	if (!t->color.token)
		return (false);
	(*clr_ptr)[3] = -1;
	return (true);
}

void	init_parsing(t_parse *t, const char *map_name)
{
	manip_reset(t);
	t->map.name = ft_strdup(map_name);
	t->map.name_len = ft_strlen(map_name);
	t->map.db = NULL;
	t->map.fd = -1;
	t->map.line_count = 0;
	t->path.no = NULL;
	t->path.ea = NULL;
	t->path.so = NULL;
	t->path.we = NULL;
	t->color.token = NULL;
	t->color.c = NULL;
	t->map.valid_map = NULL;
	t->color.f = NULL;
	t->loc.f = 0;
	t->loc.c = 0;
	t->loc.we = 0;
	t->loc.so = 0;
	t->loc.ea = 0;
	t->loc.no = 0;
	t->player.direction = '0';
	t->player.x = 0;
	t->player.y = 0;
	t->loc.current = 0;
}
