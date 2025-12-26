/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:29:18 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/26 16:16:26 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	flood_fill(char **map, size_t x, size_t y, t_parse *t)
{
	size_t	width;

	if (x >= t->map.height || x < 0)
		return (0);
	width = ft_strlen(map[x]);
	if (y >= width || y < 0)
		return (0);
	if (map[x][y] == ' ')
		return (0);
	if (map[x][y] == 'V' || map[x][y] == '1')
		return (1);
	if (map[x][y] == '0' || map[x][y] == t->player.direction)
		map[x][y] = 'V';
	else
		return (1);
	if (flood_fill(map, x, y + 1, t) == 0)
		return (0);
	if (flood_fill(map, x + 1, y, t) == 0)
		return (0);
	if (flood_fill(map, x, y - 1, t) == 0)
		return (0);
	if (flood_fill(map, x - 1, y, t) == 0)
		return (0);
	return (1);
}

void	free_copy(char **copy, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(copy[i++]);
	free(copy);
	return ;
}

bool	validate_map_format(t_parse *t)
{
	size_t	i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (t->map.height + 1));
	if (!copy)
		return (false);
	while (t->map.valid_map[i] != NULL)
	{
		copy[i] = ft_strdup(t->map.valid_map[i]);
		i++;
	}
	copy[i] = NULL;
	manip_reset(&t->manip);
	if (flood_fill(copy, t->player.x, t->player.y, t) == 0)
	{
		free_copy(copy, t->map.height);
		return (false);
	}
	free_copy(copy, t->map.height);
	return (true);
}
