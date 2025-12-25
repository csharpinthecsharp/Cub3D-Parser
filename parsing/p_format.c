/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:22:32 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 23:03:16 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool	validate_format(t_parse *t)
{
	if (!validate_path_format(t))
	{
		ft_puterror("The path format was not accepted!");
		return (false);
	}
	ft_putgood("The path format was accepted!");
	if (!validate_color_format(t))
	{
		ft_puterror("The colors format was not accepted!");
		return (false);
	}
	ft_putgood("The colors format was accepted!");
	if (!validate_global_format(t))
	{
		ft_puterror("The global format was not accepted!");
		return (false);
	}
	ft_putgood("The global format was accepted!");
	if (!validate_map_format(t))
	{
		ft_puterror("The map format was not accepted!");
		return (false);
	}
	ft_putgood("The map format was accepted!");
	return (true);
}
