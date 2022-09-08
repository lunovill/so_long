/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_frame_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:07:18 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:07:22 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_move(t_imgs *skin, char **coor, char move)
{
	unsigned int	x;
	unsigned int	y;

	x = skin->x / W_CASE;
	y = skin->y / H_CASE;
	if (move == 'N' && (skin->y % 80 == 20 && (ft_isalpha(coor[y - 1][x]) == 1
			|| (ft_isalpha(coor[y - 1][x - 1]) == 1 && skin->x % 80 < 20)
		|| (ft_isalpha(coor[y - 1][x + 1]) == 1 && skin->x % 80 > 60))))
		return (0);
	else if (move == 'E' && (skin->x % 80 == 60
			&& (ft_isalpha(coor[y][x + 1]) == 1
			|| (ft_isalpha(coor[y - 1][x + 1]) == 1 && skin->y % 80 < 20)
		|| (ft_isalpha(coor[y + 1][x + 1]) == 1 && skin->y % 80 > 60))))
		return (0);
	else if (move == 'S' && (skin->y % 80 == 60
			&& (ft_isalpha(coor[y + 1][x]) == 1
			|| (ft_isalpha(coor[y + 1][x - 1]) == 1 && skin->x % 80 < 20)
		|| (ft_isalpha(coor[y + 1][x + 1]) == 1 && skin->x % 80 > 60))))
		return (0);
	else if (move == 'W' && (skin->x % 80 == 20
			&& (ft_isalpha(coor[y][x - 1]) == 1
			|| (ft_isalpha(coor[y - 1][x - 1]) == 1 && skin->y % 80 < 20)
		|| (ft_isalpha(coor[y + 1][x - 1]) == 1 && skin->y % 80 > 60))))
		return (0);
	return (1);
}

static void	ft_in_move(t_imgs *skin, int *key, float min, float max)
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

static int	ft_move(t_map *map, t_imgs *skin, t_key *key)
{
	int	ret;

	ret = 0;
	if (key->up)
	{
		ret = ft_check_move(skin, map->coor, 'N');
		if (key->up == 1 && ret)
			skin->y -= 10;
		ft_in_move(skin, &key->up, 0, 7);
	}
	else if (key->right)
	{
		ret = ft_check_move(skin, map->coor, 'E');
		if (key->right == 1 && ret)
			skin->x += 10;
		ft_in_move(skin, &key->right, 8, 15);
	}
	return (ret);
}

static void	ft_move2(t_map *map, t_imgs *skin, t_key *key, unsigned int *count)
{
	int	ret;

	ret = ft_move(map, skin, key);
	if (key->down)
	{
		ret = ft_check_move(skin, map->coor, 'S');
		if (key->down == 1 && ret)
			skin->y += 10;
		ft_in_move(skin, &key->down, 16, 23);
	}
	else if (key->left)
	{
		ret = ft_check_move(skin, map->coor, 'W');
		if (key->left == 1 && ret)
			skin->x -= 10;
		ft_in_move(skin, &key->left, 24, 31);
	}
	if (ret)
		*count += 10;
}

void	ft_next_frame(t_mlx *mlx)
{
	ft_move2(mlx->txtr->map, mlx->txtr->skin, mlx->key, &mlx->count);
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
