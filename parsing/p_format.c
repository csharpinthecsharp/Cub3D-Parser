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
            if (t->manip.eof && (t->map.db[t->manip.a][t->manip.b] != ' '))
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
    return (token);
}

static bool validate_path_format(t_game *t)
{
    if (!init_path(t))
    {
        ft_fperror("Malloc failed (t->path)!", STDERR_FILENO, true);
        return (false);
    }
    t->path.NO = retrieve_path("NO", t->path.NO, t);
    if (!t->path.NO)
        return (false);
    t->path.SO = retrieve_path("SO", t->path.SO, t);
    if (!t->path.SO)
        return (false);
    t->path.WE = retrieve_path("WE", t->path.WE, t);
    if (!t->path.WE)
        return (false);
    t->path.EA = retrieve_path("EA", t->path.EA, t);
    if (!t->path.EA)
        return (false);
    return (true);
}

static char *retrieve_color(char request, char *token, t_game *t)
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

bool color_tokenizer(char *token, char type, t_game *t)
{
    manip_reset(t);
    while (token[t->manip.a] && (t->manip.b < MAX_LEN_RGB))
    {
        while (token[t->manip.a] == ' ')
            t->manip.a++;
        if (token[t->manip.a] == ',')
            t->manip.b++;
        if (ft_isdigit(token[t->manip.a]))
        {
            if (type == 'F')
                t->color.F[t->manip.b] = t->color.F[t->manip.b] * 10 + token[t->manip.a] - '0';
            else
                t->color.C[t->manip.b] = t->color.C[t->manip.b] * 10 + token[t->manip.a] - '0';
        }
        t->manip.a++;
    }
    if (type == 'F')
        t->color.F[t->manip.b + 1] = -1;
    else
        t->color.C[t->manip.b + 1] = -1;
    return (true);
}
/* /!\ */  
/* /!\ */
/* /!\ */
// --------> color must be beetween 0-255 ! <--------
/* /!\ */
/* /!\ */
/* /!\ */
static bool validate_color_format(t_game *t)
{
    /*if (!init_color(t))
    {
        ft_fperror("Malloc failed (t->color)!", STDERR_FILENO, true);
        return (false);
    }*/
    int len;

    len = size_for_color_token('F', t);
    t->color.token = malloc(sizeof(char) * (len + 1));
    if (!t->color.token)
        return (false);
    t->color.token = retrieve_color('F', t->color.token, t);
    t->color.F = malloc(sizeof(int) * (MAX_LEN_RGB + 1));
    if (!t->color.F)
        return (false);
    if (!color_tokenizer(t->color.token, 'F', t))
        return (false);

    ft_memset(t->color.token, 0, ft_strlen(t->color.token));

    len = size_for_color_token('C', t);
    t->color.token = malloc(sizeof(char) * (len + 1));
    if (!t->color.token)
        return (false);
    t->color.C = malloc(sizeof(int) * (MAX_LEN_RGB + 1));
    if (!t->color.C)
        return (false);
    t->color.token = retrieve_color('C', t->color.token, t);
    if (!color_tokenizer(t->color.token, 'C', t))
        return (false);
    return (true);
}

void debug(t_game *t, bool verbose)
{
    int i;

    i = 0;
    if (verbose)
    {
        printf("NORTH: %s\n", t->path.NO);
        printf("SOUTH: %s\n", t->path.SO);
        printf("EAST: %s\n", t->path.EA);
        printf("WEST: %s\n", t->path.WE);
        while (t->color.C[i] != -1)
        {
            printf("F_COLOR: %d\n", t->color.F[i]);
            i++;
        }
        i = 0;
        while (t->color.F[i] != -1)
        {
            printf("C_COLOR: %d\n", t->color.C[i]);
            i++;
        }
    }
}

bool validate_format(t_game *t)
{
    //WARNING Chaque éléments sauf la map, peut avoir des espaces:
    //EXEMPLE: 
    //NO           ./path
    //      NO ./path
    //     F      220    ,     100    ,    0        
    // 1) Locate Detail de path puis de couleur;
    // 2) reassembler les infos dans leur struct et les verifier,
    // En commencant par regarder si les paths sont correct, et enfin
    // si les couleurs sont corrects.
    // 3) Le reste est la map, enlever juste les lignes entre path et couleur jusqua map
    if (!validate_path_format(t))
    {
        ft_fperror("Failed to retrieve directions path in the .cub", STDERR_FILENO, true);
        return (false);
    }
    if (!validate_color_format(t))
    {
        ft_fperror("Failed to retrieve colors in the .cub", STDERR_FILENO, true);
        return (false);
    }
    debug(t, true);
    return (true);
}
