/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:12:59 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 01:32:11 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*retrieve_color(char request, char *token, t_parse *t)
{
	manip_reset(t);
	while (t->manip.a < t->map.line_count)
	{
		if (t->manip.eof)
			break ;
		t->manip.b = 0;
		while (t->map.db[t->manip.a][t->manip.b])
		{
			if (t->manip.eof && (t->map.db[t->manip.a][t->manip.b] != ' '))
				token[t->manip.c++] = t->map.db[t->manip.a][t->manip.b];
			if (t->map.db[t->manip.a][t->manip.b] == request)
			{
				t->manip.eof = true;
				t->manip.b++;
			}
			t->manip.b++;
		}
		t->manip.a++;
	}
	token[t->manip.c++] = '\0';
	if (!ft_strlen(token))
		return (free(token), NULL);
	return (token);
}

static int	*color_tokenizer(char *token, int *holder, t_parse *t)
{
	manip_reset(t);
	while (token[t->manip.a] && holder[t->manip.b] > -1)
	{
		if (!(ft_isdigit(token[t->manip.a]) && !(ft_isspace(token[t->manip.a])))
			&& (token[t->manip.a] != ',') && (token[t->manip.a] != '\n'))
			return (free(holder), NULL);
		while (ft_isspace(token[t->manip.a]))
			t->manip.a++;
		if (token[t->manip.a] == ',')
		{
			t->manip.count++;
			t->manip.b++;
		}
		if (t->manip.count > 2)
			return (free(holder), NULL);
		if (ft_isdigit(token[t->manip.a]))
		{
			holder[t->manip.b] = holder[t->manip.b] * 10 + token[t->manip.a]
				- '0';
			if (holder[t->manip.b] > 255)
				return (free(holder), NULL);
		}
		t->manip.a++;
	}
	return (holder);
}

bool	validate_color_format(t_parse *t)
{
	if (!init_color(t, 'F'))
		return (false);
	t->color.f = color_tokenizer(t->color.token, t->color.f, t);
	if (!t->color.f)
		return (false);
	if (!init_color(t, 'C'))
		return (false);
	t->color.c = color_tokenizer(t->color.token, t->color.c, t);
	if (!t->color.c)
		return (false);
	return (true);
}
