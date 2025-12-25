/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:49 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 01:16:18 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static bool	open_map(t_parse *t)
{
	t->map.fd = open(t->map.name, O_RDONLY);
	if (t->map.fd < 0)
		return (false);
	return (true);
}

static bool	send_map_struct(t_parse *t)
{
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	if (!init_map(t))
		return (false);
	if (t->map.line_count == 0)
		return (false);
	while (i < t->map.line_count)
	{
		line = get_next_line(t->map.fd);
		t->map.db[i++] = ft_strdup(line);
		free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(t->map.fd);
		free(line);
	}
	t->map.db[i] = NULL;
	close(t->map.fd);
	return (true);
}

bool	validate_cub(t_parse *t)
{
	if (!open_map(t))
	{
		ft_fperror("Map path not found!", STDERR_FILENO, true);
		return (false);
	}
	if (!send_map_struct(t))
	{
		ft_fperror("Failed to load the map struct!", STDERR_FILENO, true);
		close(t->map.fd);
		return (false);
	}
	return (true);
}
