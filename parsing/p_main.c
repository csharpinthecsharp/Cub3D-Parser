#include "../header.h"

bool parsing_main(t_game *t, const char *name)
{
    if (!validate_name(name))
        return (false);
    init_main(t, name);
    if (!validate_cub(t))
        return (false);
    return (true);
}