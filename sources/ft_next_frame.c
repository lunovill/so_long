/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:05:45 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/04 21:05:47 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_move(t_map *map, t_imgs *skin, char c)
{
	if (c == 'N' && !ft_isalpha(map->coor[skin->y - 1][skin->x]))
		skin->y--;
	else if (c == 'E' && !ft_isalpha(map->coor[skin->y][skin->x + 1]))
		skin->x++;
	else if (c == 'S' && !ft_isalpha(map->coor[skin->y + 1][skin->x]))
		skin->y++;
	else if (c == 'W' && !ft_isalpha(map->coor[skin->y][skin->x - 1]))
		skin->x--;
	else
		return (0);
	return (1);
}

// void	ft_next_frame(t_mlx *mlx, char c)
// {
// 	int	ret;

// 	ret = 0;
// 	mlx->txtr->map->coor[mlx->txtr->skin->y][mlx->txtr->skin->x] = '0';
// 	if (mlx->key->up)
// 		ret = ft_check_move(mlx->txtr->map, mlx->txtr->skin, c);
// 	else if (mlx->key->right)
// 		ret = ft_check_move(mlx->txtr->map, mlx->txtr->skin, c);
// 	else if (mlx->key->down)
// 		ret = ft_check_move(mlx->txtr->map, mlx->txtr->skin, c);
// 	else if (mlx->key->left)
// 		ret = ft_check_move(mlx->txtr->map, mlx->txtr->skin, c);
// 	mlx->txtr->map->coor[mlx->txtr->skin->y][mlx->txtr->skin->x] = '4';
// 	if (ret)
// 		mlx->count++;
// }

void	ft_next_frame(t_mlx *mlx, char c)
{
	mlx->txtr->map->coor[mlx->txtr->skin->y][mlx->txtr->skin->x] = '0';
	if (ft_check_move(mlx->txtr->map, mlx->txtr->skin, c))
	{
		mlx->count++;
		ft_printf("move : %u\n", mlx->count);
	}
	if (mlx->txtr->map->coor[mlx->txtr->skin->y][mlx->txtr->skin->x] == '2')
		mlx->txtr->clct->x--;
	mlx->txtr->map->coor[mlx->txtr->skin->y][mlx->txtr->skin->x] = '4';
}
