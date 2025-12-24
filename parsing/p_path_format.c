#include "../header.h"

static char *retrieve_path(char *request, char *token, t_game *t)
{
    manip_reset(t);
    while (t->manip.a < t->map.line_count)
    {
        if (t->manip.eof)
            break;
        t->manip.b = 0;
        while (t->map.db[t->manip.a][t->manip.b])
        {
            if (t->manip.eof && !ft_isspace(t->map.db[t->manip.a][t->manip.b]))
                token[t->manip.c++] = t->map.db[t->manip.a][t->manip.b];
            if ((t->map.db[t->manip.a][t->manip.b] == request[0]) &&
                    (t->map.db[t->manip.a][t->manip.b + 1] == request[1]))
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
    char *no_nl = ft_strtrim(token, "\n");
    return (free(token), no_nl);
}

bool validate_path_format(t_game *t)
{
    if (!init_path(t))
        return (false);
        
    t->path.NO = retrieve_path("NO", t->path.NO, t);
    if (!t->path.NO || !do_exist(t->path.NO))
        return (false);

    t->path.SO = retrieve_path("SO", t->path.SO, t);
    if (!t->path.SO || !do_exist(t->path.SO))
        return (false);

    t->path.WE = retrieve_path("WE", t->path.WE, t);
    if (!t->path.WE || !do_exist(t->path.WE))
        return (false);

    t->path.EA = retrieve_path("EA", t->path.EA, t);
    if (!t->path.EA || !do_exist(t->path.EA))
        return (false);
    return (true);
}
