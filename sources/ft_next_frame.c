#include "so_long.h"

static void	ft_move_map(t_map *map, int post)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (map->coor[++y])
	{
		x = -1;
		while (map->coor[y][++x])
			if (map->coor[y][x] == '4')
				break ;
		if (map->coor[y][x] == '4')
			break ;
	}
	if (post == 7)
		map->coor[y - 1][x] = '4';
	else if (post == 15)
		map->coor[y][x + 1] = '4';
	else if (post == 23)
		map->coor[y + 1][x] = '4';
	else if (post == 31)
		map->coor[y][x - 1] = '4';
	map->coor[y][x] = '0';
}

void ft_next_frame(t_mlx *mlx)
{
    int skin;
    int clct;

    skin = ft_atoi(mlx->txtr.skin.data.post);
    clct = ft_atoi(mlx->txtr.clct.data.post);
	if ((skin % 8) == 7)
	{
		ft_move_map(&mlx->txtr.map, skin);
		ft_post(&mlx->txtr.skin.data.post, skin - 7);
	}
	else if ((skin % 8) != 0)
		ft_post(&mlx->txtr.skin.data.post, skin + 1);
	if (clct == COLLECTIBLE_SIZE - 1)
		ft_post(&mlx->txtr.clct.data.post, 0);
	else if (mlx->speed-- == 0)
	{
		ft_post(&mlx->txtr.clct.data.post, clct + 1);
		mlx->speed = SPEED;
	}
}