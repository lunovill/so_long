#include "so_long.h"

void	ft_create_map(t_data *data, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if ('0' <= map->coor[y][x] && map->coor[y][x] <= '4')
				map->img->data->img = map->img->frame[BACKGROUND_SIZE - 1];
			else
				map->img->data->img = map->img->frame[map->coor[y][x] - 'A'];
			mlx_draw_image(data, map->img->data, x, y);
		}
	}
}