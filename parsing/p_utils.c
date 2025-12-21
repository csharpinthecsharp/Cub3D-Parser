#include "../header.h"

void clear_gnl(int fd)
{
    char *line;

    line = NULL;
    while ((line = get_next_line(fd)))
        free(line);
}

void manip_reset(t_game *t)
{
    t->manip.a = 0;
    t->manip.b = 0;
    t->manip.c = 0;
    t->manip.eof = false;
    t->manip.count = 0;
}
