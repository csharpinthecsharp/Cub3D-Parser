#include "../header.h"

void free_main(t_game *t)
{
    free(t->map.name);
    return ;
}