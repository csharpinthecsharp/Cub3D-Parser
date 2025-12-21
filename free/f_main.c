#include "../header.h"

static void free_map(t_game *t)
{
    size_t i;

    i = 0;
    free(t->map.name);
    while (i < t->map.line_count)
        free(t->map.db[i++]);
    free(t->map.db);
    return ;
}

static void free_path(t_game *t)
{
    free(t->path.NO);
    free(t->path.EA);
    free(t->path.SO);
    free(t->path.WE);
}

void free_main(t_game *t)
{
    free_map(t);
    free_path(t);
    return ;
}