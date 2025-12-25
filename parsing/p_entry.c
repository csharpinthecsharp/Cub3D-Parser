/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_entry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:23:07 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 22:56:27 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool	parsing_main(t_parse *t, const char *name)
{
	init_parsing(t, name);
	if (!validate_name(name))
		return (false);
	if (!validate_cub(t))
		return (false);
	if (!validate_format(t))
		return (false);
	return (true);
}
