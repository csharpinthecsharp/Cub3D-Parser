/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:31:06 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 18:19:26 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

void	free_parsing(t_parse *t);
void	init_parsing(t_parse *t, const char *map_name);
bool	init_map(t_parse *t);
bool	init_path(t_parse *t);
bool	init_color(t_parse *t, char type);
bool	parsing_main(t_parse *t, const char *map_name);
bool	validate_name(const char *map_name);
bool	validate_cub(t_parse *t);
bool	validate_format(t_parse *t);
bool	validate_path_format(t_parse *t);
bool	validate_color_format(t_parse *t);
bool	validate_global_format(t_parse *t);
bool	validate_map_format(t_parse *t);
char	*retrieve_color(char request, char *token, t_parse *t);
void	manip_reset(t_manip *m);
bool	do_exist(const char *path);
bool	ft_iselement(char *str, bool find_for_player, t_parse *t);
bool	ft_isplayer(char c);
size_t	size_for_line_count(const char *name);
size_t	size_for_path(char *request, t_parse *t);
size_t	size_for_color_token(char request, t_parse *t);
size_t	size_for_new_db(t_parse *t, t_manip *m);
#endif