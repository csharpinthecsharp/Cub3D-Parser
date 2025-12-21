#include "../header.h"

bool parsing_main(t_game *t, const char *name)
{
    init_main(t, name);
    if (!validate_name(name))
        return (false);
    if (!validate_cub(t))
        return (false);
    if (!validate_format(t))
        return (false);
    return (true);
}