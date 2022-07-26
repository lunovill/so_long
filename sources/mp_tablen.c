#include "so_long.h"

size_t	mp_tablen(char **map)
{
	size_t	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}