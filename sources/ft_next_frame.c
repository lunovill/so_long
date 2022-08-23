#include "so_long.h"

static int	ft_check_move(t_imgs *skin, char **coor, char move)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	sx;
	unsigned int	sy;

	sx = skin->x + 40;
	sy = skin->y + 40;
	x  = sx / W_CASE;
	y  = sy / H_CASE;
// ft_printf("%c : x = %u, y = %u\n", move, sx % 80, sy % 80);
	if (move == 'N' && (sy % 80 == 20 && (ft_isalpha(coor[y - 1][x]) == 1 || (ft_isalpha(coor[y - 1][x - 1]) == 1 && sx % 80 < 20) || (ft_isalpha(coor[y - 1][x + 1]) == 1 && sx % 80 > 60))))
		return (0);
	else if (move == 'E' && (sx % 80 == 60 && (ft_isalpha(coor[y][x + 1]) == 1 || (ft_isalpha(coor[y - 1][x + 1]) == 1 && sy % 80 < 20) || (ft_isalpha(coor[y + 1][x + 1]) == 1 && sy % 80 > 60))))
		return (0);
	else if (move == 'S' && (sy % 80 == 60 && (ft_isalpha(coor[y + 1][x]) == 1 || (ft_isalpha(coor[y + 1][x - 1]) == 1 && sx % 80 < 20) || (ft_isalpha(coor[y + 1][x + 1]) == 1 && sx % 80 > 60))))
		return (0);
	else if (move == 'W' && (sx % 80 == 20 && (ft_isalpha(coor[y][x - 1]) == 1 || (ft_isalpha(coor[y - 1][x - 1]) == 1 && sy % 80 < 20) || (ft_isalpha(coor[y + 1][x - 1]) == 1 && sy % 80 > 60))))
		return (0);
	return (1);
}

static void ft_in_move(t_imgs *skin, int *key, float min, float max)
{
	if (*key == 1)
	{
		if (min <= skin->index && skin->index < max)
			skin->index++;
		else
			skin->index = min;
	}
	else if (*key == 2)
	{
		skin->index = min;
		*key = 0;
	}
}

static void ft_move(t_map *map, t_imgs *skin, t_key *key)
{
	if (key->up)
	{
		if (key->up == 1 && ft_check_move(skin, map->coor, 'N'))
			skin->y -= 10;
		ft_in_move(skin, &key->up, 0, 7);
	}
	else if (key->right)
	{
		if (key->right == 1 && ft_check_move(skin, map->coor, 'E'))
			skin->x += 10;
		ft_in_move(skin, &key->right, 8, 15);
	}
	else if (key->down)
	{
		if (key->down == 1 && ft_check_move(skin, map->coor, 'S'))
			skin->y += 10;
		ft_in_move(skin, &key->down, 16, 23);
	}
	else if (key->left)
	{
		if (key->left == 1 && ft_check_move(skin, map->coor, 'W'))
			skin->x -= 10;
		ft_in_move(skin, &key->left, 24, 31);
	}
}

void ft_next_frame(t_mlx *mlx)
{
	ft_move(mlx->txtr->map, mlx->txtr->skin, mlx->key);
	if (mlx->speed-- == 0)
	{
		if (mlx->txtr->clct->index == CLCT_SIZE - 1)
			mlx->txtr->clct->index = 0;
		else
			mlx->txtr->clct->index++;
		if (mlx->txtr->exit->index == EXIT_SIZE - 1)
			mlx->txtr->exit->index = 0;
		else
			mlx->txtr->exit->index++;
		mlx->speed = SPEED;
	}
}
