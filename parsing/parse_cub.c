#include "../header.h"

bool validate_cub(t_game *t)
{
    char* line;
    size_t i;

    i = 0;
    line = NULL;
    t->map.fd = open(t->map.name, O_RDONLY);
    if (t->map.fd < 0)
    {
        ft_fperror("Bad file descriptor!", STDERR_FILENO, true);
        return (false);
    }
    if (!init_map(t))
        return (false);
    while (i < t->map.line_count)
    {
        line = get_next_line(t->map.fd);
        t->map.db[i++] = ft_strdup(line);
        free(line);
    }
    t->map.db[i] = NULL;
    clear_gnl(t->map.fd);
    close(t->map.fd);
    return (true);
}
