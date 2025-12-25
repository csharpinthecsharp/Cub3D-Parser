/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:16 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 17:54:35 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	free_map(t_parse *t)
{
	size_t	i;

	i = 0;
	free(t->map.name);
	if (t->map.line_count)
	{
		while (i < (t->map.line_count))
			free(t->map.db[i++]);
		free(t->map.db);
	}
	i = 0;
	if (t->map.valid_map)
	{
		while (i < t->map.height)
			free(t->map.valid_map[i++]);
		free(t->map.valid_map);
	}
	return ;
}

static void	free_path(t_parse *t)
{
	free(t->path.no);
	free(t->path.ea);
	free(t->path.so);
	free(t->path.we);
}

static void	free_color(t_parse *t)
{
	free(t->color.token);
}

void	free_parsing(t_parse *t)
{
	free_map(t);
	free_path(t);
	free_color(t);
	return ;
}
