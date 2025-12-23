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

char **push_clean_db(t_game *t)
{
    char **new_db;

    new_db = malloc(sizeof(char *) * (size_for_new_db(t) + 1));
    if (!new_db)
        return (NULL);

    while (t->manip.a < t->map.line_count)
    {
        if (t->map.db[t->manip.a])
        {
            while (ft_isspace(t->map.db[t->manip.a][t->manip.b]))
                t->manip.b++;
            while (t->map.db[t->manip.a][t->manip.b])
            {
                new_db[t->manip.c] = malloc(sizeof(char) * ft_strlen(t->map.db[t->manip.a]));
                if (!new_db[t->manip.c])
                    return (NULL);
                new_db[t->manip.c][t->manip.d++] = t->map.db[t->manip.a][t->manip.b++];
            }
            if (ft_strlen(new_db[t->manip.a]) > 0)
                t->manip.c++;
        }
        t->manip.a++;
    }
    return (new_db);
}

bool validate_global_format(t_game *t)
{
            // apres avoir localisé (loc_line) de chaque element,
        // je vais verifier que les autres lignes sont bien vides, sinon false.
        // si une ligne contient que des 1, alors le reste sera la map.
    manip_reset(t);
    remove_line(&t->map, &t->loc);
    t->map.line_count -= 6;
    t->map.db = push_clean_db(t);
    if (!t->map.db)
        return (false);
    //Apres que la nouvelle map sois push, on verifie que si il y a une autre charactere que
    // 1, 0, N, S, E, W alors la map est false; 
    return (true);
}