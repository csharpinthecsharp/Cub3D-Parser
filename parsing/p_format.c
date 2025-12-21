#include "../header.h"

char *retrieve_path(char *request, char *holder, t_game *t)
{
    manip_reset(t);
    while (t->manip.a < t->map.line_count)
    {
        if (t->manip.eof)
            break;
        t->manip.b = 0;
        while (t->map.db[t->manip.a][t->manip.b])
        {
            if (t->manip.eof && (t->map.db[t->manip.a][t->manip.b] != ' '))
                holder[t->manip.c++] = t->map.db[t->manip.a][t->manip.b];
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
    holder[t->manip.c++] = '\0';
    if (!ft_strlen(holder))
        return (free(holder), NULL);
    return (holder);
}

bool validate_format(t_game *t)
{
    //WARNING Chaque éléments sauf la map, peut avoir des espaces:
    //EXEMPLE: 
    //NO           ./path
    //      NO ./path
    //     F      220    ,     100    ,    0        
    // 1) Separer la map des details;
    // 2) Locate Detail de path puis de couleur;
    // 3) Detail + Path minimum de 6 lignes; si + de lignes verifier,
    // quelles soit toutes empty.
    // 4) enfin, reassembler les infos dans leur struct et les verifier,
    // En commencant par regarder si les paths sont correct, et enfin
    // si les couleurs sont corrects.
    if (!init_path(t))
    {
        ft_fperror("Malloc failed (t->path)!", STDERR_FILENO, true);
        return (false);
    }
    t->path.NO = retrieve_path("NO", t->path.NO, t);
    if (!t->path.NO)
    {
        ft_fperror("Failed to retrieve north path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    t->path.SO = retrieve_path("SO", t->path.SO, t);
    if (!t->path.SO)
    {
        ft_fperror("Failed to retrieve south path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    t->path.WE = retrieve_path("WE", t->path.WE, t);
    if (!t->path.WE)
    {
        ft_fperror("Failed to retrieve west path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    t->path.EA = retrieve_path("EA", t->path.EA, t);
    if (!t->path.EA)
    {
        ft_fperror("Failed to retrieve east path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    return (true);
}
