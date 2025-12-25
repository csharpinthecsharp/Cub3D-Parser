/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:31:08 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 01:31:51 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef struct s_loc
{
	size_t		current;
	size_t		no;
	size_t		so;
	size_t		we;
	size_t		ea;
	size_t		f;
	size_t		c;
}				t_loc;

typedef struct s_path
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_path;

typedef struct s_color
{
	char		*token;
	int			*f;
	int			*c;
}				t_color;

typedef struct s_player
{
	int			x;
	int			y;
	char		direction;
}				t_player;

typedef struct s_map
{
	char		*name;
	char		**db;
	char		**valid_map;
	int			fd;
	size_t		line_count;
	size_t		name_len;
}				t_map;

typedef struct s_manip
{
	size_t		a;
	size_t		b;
	size_t		c;
	size_t		d;
	bool		eof;
	size_t		count;
}				t_manip;

typedef struct s_parse
{
	t_map		map;
	t_color		color;
	t_path		path;
	t_manip		manip;
	t_loc		loc;
	t_player	player;
}				t_parse;

#endif