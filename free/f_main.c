#include "../header.h"

void free_map(t_game *t)
{
    size_t i;

    i = 0;
    free(t->map.name);
    while (i < t->map.line_count)
        free(t->map.db[i++]);
    free(t->map.db);
    return ;
}
void free_main(t_game *t)
{
    free_map(t);
    return ;
}