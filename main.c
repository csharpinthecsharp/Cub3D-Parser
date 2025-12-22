#include "header.h"

int main( int ac, char **av )
{
    // https://harm-smits.github.io/42docs/projects/cub3d <--- FOR RAYCASTING
    (void)av;
    t_game game;
    t_game *t;
    t = &game;
    if (ac != 2)
    {
        ft_fperror("Expected 1 argument (*.cub)!", STDERR_FILENO, true);
        return (1);
    }
    if (!parsing_main(t, av[1]))
    {
        free_main(t);
        return (1);
    }
    free_main(t);
    return (0);
}