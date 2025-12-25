/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:31:08 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 18:24:51 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef struct s_path
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	size_t		loc[4];
}				t_path;

typedef struct s_color
{
	char		*token;
	int			f[3];
	int			c[3];
	size_t		loc[2];
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
	size_t		name_len;
	char		**db;
	size_t		line_count;
	int			fd;
	
	char		**valid_map;
	size_t		height;
	size_t		current;
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
	t_player	player;
}				t_parse;

#endif