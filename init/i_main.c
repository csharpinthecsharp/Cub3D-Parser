#include "../header.h"

void init_main(t_game *t, const char *map_name)
{
    t->map.name = ft_strdup(map_name);
    t->map.name_len = ft_strlen(map_name);
    t->map.x = 0;
    t->map.y = 0;
    t->map.fd = -1;
    return ;
}