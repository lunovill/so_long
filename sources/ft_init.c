/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:49:12 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:49:13 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_find_coor(t_imgs *sprt, char **coor, char c)
{
	int		x;
	int		y;

	y = -1;
	while (coor[++y])
	{
		x = -1;
		while (coor[y][++x])
			if (coor[y][x] == c)
				break ;
		if (coor[y][x] == c)
			break ;
	}	
	sprt->x = x;
	sprt->y = y;
}

static void	ft_init_sprt(t_mlx *mlx, t_imgs *sprt, unsigned int id, int set)
{
	if (set == 4)
		sprt->index = 16;
	else
		sprt->index = 0;
	sprt->frame = mlx_opsprt(mlx->init, sprt, id, sprt->index);
	if (!sprt->frame)
		ft_error("", "", mlx);
	if (set == 3 || set == 4)
		ft_find_coor(sprt, mlx->txtr->map->coor, set + '0');
}

int	ft_init(t_mlx *mlx, t_map *map)
{
	mlx = mlx_malloc(mlx, map);
	if (!mlx)
		return (ft_ftab(map->coor), ft_free(map),
			ft_error("mlx:\t", "malloc error", mlx));
	mlx->txtr->map->img->path = ft_strdup(BACKGROUND);
	mlx->txtr->map->frame
		= mlx_opmap(mlx->init, mlx->txtr->map, BACKGROUND_SIZE);
	ft_free(mlx->txtr->map->img->path);
	mlx->txtr->clct->path = ft_strdup(CLCT_PATH);
	ft_init_sprt(mlx, mlx->txtr->clct, CLCT_INDEX, 2);
	ft_free(mlx->txtr->clct->path);
	mlx->txtr->exit->path = ft_strdup(EXIT_PATH);
	ft_init_sprt(mlx, mlx->txtr->exit, EXIT_INDEX, 3);
	ft_free(mlx->txtr->exit->path);
	mlx->txtr->skin->path = ft_strdup(SKIN_PATH);
	ft_init_sprt(mlx, mlx->txtr->skin, SKIN_INDEX, 4);
	ft_free(mlx->txtr->skin->path);
	mlx->key->up = 0;
	mlx->key->right = 0;
	mlx->key->down = 0;
	mlx->key->left = 0;
	mlx->count = 0;
	return (0);
}
