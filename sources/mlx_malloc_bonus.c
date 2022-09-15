/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_malloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:32:35 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/15 01:11:48 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_init_txtr(t_txtr *txtr, t_map *map)
{
	txtr->data = NULL;
	txtr->map = map;
	txtr->clct = NULL;
	txtr->exit = NULL;
	txtr->skin = NULL;
}

static t_imgs	*mlx_malloc_sprt(void)
{
	t_imgs	*sprt;

	sprt = (t_imgs *)malloc(sizeof(t_imgs));
	if (!sprt)
		return (NULL);
	sprt->frame = NULL;
	sprt->data = (t_data *)malloc(sizeof(t_data));
	if (!sprt->data)
		return (ft_free(sprt), NULL);
	sprt->data->img = NULL;
	return (sprt);
}

int	mlx_malloc(t_mlx *mlx, t_map *map)
{
	mlx->txtr = (t_txtr *)malloc(sizeof(t_txtr));
	if (!mlx->txtr)
		return (ft_ftab(map->coor), ft_free(map), -1);
	ft_init_txtr(mlx->txtr, map);
	mlx->txtr->map->img = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->map->img)
		return (-1);
	mlx->txtr->map->img->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->map->img->data)
		return (-1);
	mlx->txtr->clct = mlx_malloc_sprt();
	if (!mlx->txtr->clct)
		return (-1);
	mlx->txtr->exit = mlx_malloc_sprt();
	if (!mlx->txtr->exit)
		return (-1);
	mlx->txtr->skin = mlx_malloc_sprt();
	if (!mlx->txtr->skin)
		return (-1);
	mlx->key = (t_key *)malloc(sizeof(t_key));
	if (!mlx->key)
		return (-1);
	return (0);
}
