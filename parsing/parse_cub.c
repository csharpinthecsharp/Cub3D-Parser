#include "../header.h"

bool validate_cub(t_game *t)
{
    char* line;

    line = NULL;
    t->map.fd = open(t->map.name, O_RDONLY);
    if (t->map.fd < 0)
    {
        ft_fperror("Bad file descriptor!", STDERR_FILENO, true);
        return (false);
    }

    while (1)
    {
        // ALLOCATE MAP DB NOW DUMBASS
        line = get_next_line(t->map.fd);
        if (!line)
            break;
        t->map.db[t->map.x++] = ft_strdup(line);
        free(line);
    }
    close(t->map.fd);
    return (true);
}
