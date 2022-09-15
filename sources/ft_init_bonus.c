/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:06:31 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:06:33 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	sprt->x = x * W_CASE;
	sprt->y = y * H_CASE;
	if (c == '4')
	{
		sprt->x += 40;
		sprt->y += 40;
	}
}

static int	ft_init_sprt(t_mlx *mlx, t_imgs *sprt, int set)
{
	if (!sprt->path)
		return (ft_error("textures:\t", "malloc error", NULL));
	if (set == 4)
		sprt->index = 16;
	else
		sprt->index = 0;
	if (set == 2)
	{
		if (mlx_opsprt(mlx->init, sprt, CLCT_INDEX, CLCT_SIZE) == -1)
			return (-1);
	}
	else if (set == 3)
	{
		if (mlx_opsprt(mlx->init, sprt, EXIT_INDEX, EXIT_SIZE) == -1)
			return (-1);
	}
	else if (set == 4)
	{
		if (mlx_opsprt(mlx->init, sprt, SKIN_INDEX, SKIN_SIZE) == -1)
			return (-1);
	}
	if (set == 3 || set == 4)
		ft_find_coor(sprt, mlx->txtr->map->coor, set + '0');
	return (0);
}

int	ft_init(t_mlx *mlx, t_map *map)
{
	if (mlx_malloc(mlx, map) == -1)
		return (ft_error("mlx:\t", "malloc error", NULL));
	mlx->txtr->map->img->path = ft_strdup(BKGD);
	if (mlx_opmap(mlx->init, mlx->txtr->map, BKGD_SIZE) == -1)
		return (ft_free(mlx->txtr->map->img->path), -1);
	ft_free(mlx->txtr->map->img->path);
	mlx->txtr->clct->path = ft_strdup(CLCT_PATH);
	if (ft_init_sprt(mlx, mlx->txtr->clct, 2) == -1)
		return (ft_free(mlx->txtr->clct->path), -1);
	ft_free(mlx->txtr->clct->path);
	mlx->txtr->exit->path = ft_strdup(EXIT_PATH);
	if (ft_init_sprt(mlx, mlx->txtr->exit, 3) == -1)
		return (ft_free(mlx->txtr->exit->path), -1);
	ft_free(mlx->txtr->exit->path);
	mlx->txtr->skin->path = ft_strdup(SKIN_PATH);
	if (ft_init_sprt(mlx, mlx->txtr->skin, 4) == -1)
		return (ft_free(mlx->txtr->skin->path), -1);
	ft_free(mlx->txtr->skin->path);
	mlx->key->up = 0;
	mlx->key->right = 0;
	mlx->key->down = 0;
	mlx->key->left = 0;
	mlx->count = 0;
	mlx->speed = 0;
	return (0);
}
