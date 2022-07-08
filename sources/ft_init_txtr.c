#include "so_long.h"

void    ft_init_txtr(t_txtr *txtr, t_map *map)
{
    map->path = ft_strdup(BACKGROUND);
	txtr->skin.path = ft_strdup(SKIN);
    txtr->skin.data.index = 8;
}