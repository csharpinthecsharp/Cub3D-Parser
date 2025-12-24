#include "../header.h"

static void remove_line(t_map *m, t_loc *t)
{
    free(m->db[t->SO]);
    m->db[t->SO] = NULL;
    free(m->db[t->NO]);
    m->db[t->NO] = NULL;
    free(m->db[t->EA]);
    m->db[t->EA] = NULL;
    free(m->db[t->WE]);
    m->db[t->WE] = NULL;
    free(m->db[t->F]);
    m->db[t->F] = NULL;
    free(m->db[t->C]);
    m->db[t->C] = NULL;
}

static void push_line_to_db(t_game *t, t_manip *m) 
{
    while (t->map.db[m->a][m->c++])
    {
        if (t->map.db[m->a][m->c] != '\n')
        {
            while (ft_isspace(t->map.db[m->a][m->c]))
                m->c++;
            t->map.valid_map[m->b][m->d++] = t->map.db[m->a][m->c];
        }
    }
}

static bool filter_db(t_game *t, t_manip *m)
{
    manip_reset(t);
    while (m->a++ < t->map.line_count)
    {
        if (t->map.db[m->a] != NULL)
        {
            m->count = ft_strlen(t->map.db[m->a]);
            if (t->map.db[m->a] && m->count > 2)
            {
                if (!ft_iselement(t->map.db[m->a]))
                    return (false);
                m->count--;
                t->map.valid_map[m->b] = malloc(sizeof(char) * (m->count + 1));
                if (!t->map.valid_map[m->b])
                    return (false);
                m->d = 0;
                m->c = 0;
                push_line_to_db(t, m);
                t->map.valid_map[m->b][m->d] = '\0';
                m->b++;
            }
        }
    }
    return (t->map.valid_map[m->b] = NULL, true);
}

bool validate_global_format(t_game *t)
{
    size_t len;
    (void)len;
    remove_line(&t->map, &t->loc);
    len = size_for_new_db(t, &t->manip);
    if (len == 0)
        return (false);
    t->map.valid_map = malloc(sizeof(char *) * (len + 1));
    if (!t->map.valid_map)
        return (false);
    if (!filter_db(t, &t->manip))
        return (false);
    if (!t->map.valid_map)
        return (false);
    return (true);
}
