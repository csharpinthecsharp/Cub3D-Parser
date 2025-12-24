#include "../header.h"

void remove_line(t_map *m, t_loc *t)
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
#include <string.h>
static bool push_valid_map(t_game *t, t_manip *m)
{
    size_t n;

    manip_reset(t);
    t->map.valid_map = malloc(sizeof(char *) * (10000 + 1));
    if (!t->map.valid_map)
        return (false);
    while (m->a < t->map.line_count)
    {
        if (t->map.db[m->a] != NULL)
        {
            n = ft_strlen(t->map.db[m->a]);
            if (t->map.db[m->a + 1] != NULL && n > 2)
            {   
                n--;
                t->map.valid_map[m->b] = malloc(sizeof(char) * (n + 1));
                m->d = 0;
                m->c = 0;
                while (t->map.db[m->a][m->c])
                {
                    if (((!ft_isspace(t->map.db[m->a][m->c]) && (t->map.db[m->a][m->c] != '1')
                        && (t->map.db[m->a][m->c] != '0') && (t->map.db[m->a][m->c] != 'N')
                        && (t->map.db[m->a][m->c] != 'S') && (t->map.db[m->a][m->c] != 'E')
                        && (t->map.db[m->a][m->c] != 'W') && (t->map.db[m->a][m->c] != '\n'))))
                            return (false);
                    if (t->map.db[m->a][m->c] != '\n')
                    {
                        while (ft_isspace(t->map.db[m->a][m->c]))
                            m->c++;
                        t->map.valid_map[m->b][m->d++] = t->map.db[m->a][m->c];
                    }
                    m->c++;
                }
                t->map.valid_map[m->b][m->d] = '\0';
                m->b++;
            }
        }
        m->a++;
    }
    t->map.valid_map[m->b] = NULL;
    return (true);
}

bool validate_global_format(t_game *t)
{
            // apres avoir localisé (loc_line) de chaque element,
        // je vais verifier que les autres lignes sont bien vides, sinon false.
        // si une ligne contient que des 1, alors le reste sera la map.*
    remove_line(&t->map, &t->loc);
    if (!push_valid_map(t, &t->manip))
        return (false);
    if (!t->map.valid_map)
        return (false);
    //Apres que la nouvelle map sois push, on verifie que si il y a une autre charactere que
    // 1, 0, N, S, E, W alors la map est false; 
    return (true);
}