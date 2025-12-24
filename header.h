#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdbool.h>
#include <fcntl.h>

#define MAX_LEN_RGB 3
#define ELEMENTS 6

typedef struct s_loc {
    size_t current;
    size_t NO;
    size_t SO;
    size_t WE;
    size_t EA;
    size_t F;
    size_t C;
} t_loc;

typedef struct s_path {
    char *NO;
    char *SO;
    char *WE;
    char *EA;
} t_path;

typedef struct s_color {
    char *token;
    int *F;
    int *C;
} t_color;

typedef struct s_map {
    char *name;
    char **db;
    char **valid_map;
    int fd;
    size_t line_count;
    size_t name_len;
} t_map;

typedef struct s_manip {
    size_t a;
    size_t b;
    size_t c;
    size_t d;
    bool eof;
    size_t count;
} t_manip;

typedef struct s_game {
    t_map map;
    t_color color;
    t_path path;
    t_manip manip;
    t_loc loc;
} t_game;

/* FREE*/
void free_main(t_game *t); /* END FREE */
/* INIT */
void init_main(t_game *t, const char *map_name); 
bool init_map(t_game *t); 
bool init_path(t_game *t);
bool init_color(t_game *t, char type); /* END INIT */
/* PARSING */
bool parsing_main(t_game *t, const char *map_name);
bool validate_name(const char *map_name);
bool validate_cub(t_game *t);
bool validate_format(t_game *t);
bool validate_path_format(t_game *t);
bool validate_color_format(t_game *t);
bool validate_global_format(t_game *t);
bool validate_map_format(t_game *t);
char *retrieve_color(char request, char *token, t_game *t); 
void manip_reset(t_game *t);
bool do_exist(const char *path);
bool ft_iselement(char *str);
size_t size_for_line_count(const char *name);
size_t size_for_path(char *request, t_game *t); 
size_t size_for_color_token(char request, t_game *t);
size_t size_for_new_db(t_game *t, t_manip *m); /* END PARSING */
#endif //HEADER_H