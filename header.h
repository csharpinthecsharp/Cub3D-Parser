#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_map {
    char *name;
    const char **db;
    int fd;
    int x;
    int y;
    size_t name_len;
} t_map;

typedef struct s_game {
    t_map map;
    bool running;
} t_game;

/* FREE*/
void free_main(t_game *t); /* END FREE */
/* INIT */
void init_main(t_game *t, const char *map_name); /* END INIT */
/* PARSING */
bool parsing_main(t_game *t, const char *map_name);
bool validate_name(const char *map_name);
bool validate_cub(t_game *t);
/* END PARSING */
#endif //HEADER_H