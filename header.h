#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdbool.h>
#include <fcntl.h>
#include "mlx/mlx.h"

typedef struct s_path {
    char *NO;
    char *SO;
    char *WE;
    char *EA;
} t_path;

typedef struct s_info {
    int *F_color;
    int *C_color;
} t_info;

typedef struct s_line {
    size_t size;
} t_line;

typedef struct s_map {
    char *name;
    char **db;
    int fd;
    size_t line_count;
    size_t name_len;

    t_line line;
} t_map;

typedef struct s_manip {
    size_t a;
    size_t b;
    size_t c;
    bool eof;
    size_t count;
} t_manip;

typedef struct s_game {
    t_map map;
    t_info info;
    t_path path;
    t_manip manip;
} t_game;

/* FREE*/
void free_main(t_game *t); /* END FREE */
/* INIT */
void init_main(t_game *t, const char *map_name); 
bool init_map(t_game *t); 
bool init_path(t_game *t); /* END INIT */
/* PARSING */
bool parsing_main(t_game *t, const char *map_name);
bool validate_name(const char *map_name);
bool validate_cub(t_game *t);
bool validate_format(t_game *t);
void clear_gnl(int fd); 
void manip_reset(t_game *t);
size_t size_for_line_count(const char *name);
size_t size_for_path(char *request, t_game *t); /* END PARSING */
#endif //HEADER_H