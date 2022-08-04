#include "so_long.h"

static void	ft_move_map(t_map *map, t_imgs *skin, int post)
{
	map->coor[skin->y][skin->x] = '0';
	if (post == 7)
		map->coor[--skin->y][skin->x] = '4';
	else if (post == 15)
		map->coor[skin->y][++skin->x] = '4';
	else if (post == 23)
		map->coor[++skin->y][skin->x] = '4';
	else if (post == 31)
		map->coor[skin->y][--skin->x] = '4';
}

void ft_next_frame(t_mlx *mlx)
{
    int skin;
    int clct;
    int exit;

    skin = ft_atoi(mlx->txtr.skin.data.post);
    clct = ft_atoi(mlx->txtr.clct.data.post);
    exit = ft_atoi(mlx->txtr.exit.data.post);
	if ((skin % 8) == 7)
	{
		ft_move_map(&mlx->txtr.map, &mlx->txtr.skin, skin);
		ft_post(&mlx->txtr.skin.data.post, skin - 7);
	}
	else if ((skin % 8) != 0)
		ft_post(&mlx->txtr.skin.data.post, skin + 1);
	if (clct == COLLECTIBLE_SIZE - 1)
		ft_post(&mlx->txtr.clct.data.post, 0);
	if (exit == EXIT_SIZE - 1)
		ft_post(&mlx->txtr.exit.data.post, 0);
	else if (mlx->speed-- == 0)
	{
		ft_post(&mlx->txtr.clct.data.post, clct + 1);
		ft_post(&mlx->txtr.exit.data.post, exit + 1);
		mlx->speed = SPEED;
	}
}