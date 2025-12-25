/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:12:59 by ltrillar          #+#    #+#             */
/*   Updated: 2025/12/25 21:48:31 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*retrieve_color(char request, char *token, t_parse *t)
{
	manip_reset(&t->manip);
	while (t->manip.a < t->map.line_count)
	{
		if (t->manip.eof)
			break ;
		t->manip.b = 0;
		while (t->map.db[t->manip.a][t->manip.b])
		{
			if (t->manip.eof && !ft_isspace(t->map.db[t->manip.a][t->manip.b]))
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
	token[t->manip.c] = '\0';
	if (!ft_strlen(token))
		return (free(token), NULL);
	return (token);
}

static bool add_color_to_ptr(char *token, int *ptr, t_manip *m)
{
	if (token[m->a] == ',')
	{
		m->count++;
		m->b++;
		if (m->count > 2)
			return (false);
	}
	else if (ft_isdigit(token[m->a]))
	{
		if (ptr[m->b] == -1)
			ptr[m->b] = 0;
		ptr[m->b] = ptr[m->b] * 10 + token[m->a] - '0';
		if (ptr[m->b] > 255)
			return (false);
	}
	else
        return (false);
	return (true);
}
static bool color_tokenizer(char *token, int *ptr, t_manip *m)
{
    manip_reset(m);
    while (token[m->a] && m->b < 3)
    {
        if (ft_isspace(token[m->a]))
        {
            m->a++;
            continue;
        }
        if (!add_color_to_ptr(token, ptr, m))
			return (false);
        m->a++;
    }
    if (m->count != 2 || ptr[0] == -1 || ptr[1] == -1 || ptr[2] == -1)
        return (false);
    return (true);
}

bool	validate_color_format(t_parse *t)
{
	if (!init_color(t, 'F'))
		return (false);
	if (!color_tokenizer(t->color.token, t->color.f, &t->manip))
		return (false);
	
	if (!init_color(t, 'C'))
		return (false);
	if (!color_tokenizer(t->color.token, t->color.c, &t->manip))
		return (false);
	return (true);
}
