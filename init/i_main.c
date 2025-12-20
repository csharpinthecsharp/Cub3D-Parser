#include "../header.h"

bool init_map(t_game *t)
{
    t->map.line_count = count_line(t->map.name);
    t->map.db = malloc(sizeof(char *) * (t->map.line_count + 1));
    if (!t->map.db)
    {
        ft_fperror("Malloc failed (t->map.db)!", STDERR_FILENO, true);
        close(t->map.fd);
        return (false);
    }
    return (true);
}

void init_main(t_game *t, const char *map_name)
{
    t->map.name = ft_strdup(map_name);
    t->map.name_len = ft_strlen(map_name);
    t->map.x = 0;
    t->map.y = 0;
    t->map.db = NULL;
    t->map.fd = -1;
    t->map.line_count = 0;
    return ;
}