/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_name.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:44 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/26 16:09:28 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static bool	validate_name_format(const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(name + len - 4, ".cub", 5) == 0)
		return (true);
	return (false);
}

bool	validate_name(const char *name)
{
	if (!(ft_strlen(name) > 4))
	{
		ft_puterror("Map name size should be greater");
	}
	if (!validate_name_format(name))
	{
		ft_puterror("Map name contains no .cub!");
		return (false);
	}
	return (true);
}
