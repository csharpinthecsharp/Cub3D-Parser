#include "../header.h"

size_t count_line(const char *name)
{
    size_t count;
    char *line;
    int fd;

    count = 0;
    line = NULL;
    fd = open(name, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        count++;
    }
    close(fd);
    return (count);
}

void clear_gnl(int fd)
{
    char *line;

    line = NULL;
    while ((line = get_next_line(fd)))
        free(line);
}
