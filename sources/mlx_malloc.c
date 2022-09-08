/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:32:35 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/04 16:24:10 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_imgs	*mlx_malloc_sprt(void)
{
	t_imgs	*sprt;

	sprt = (t_imgs *)malloc(sizeof(t_imgs));
	if (!sprt)
		return (NULL);
	sprt->data = (t_data *)malloc(sizeof(t_data));
	if (!sprt->data)
		return (ft_free(sprt), NULL);
	return (sprt);
}

t_mlx	*mlx_malloc(t_mlx *mlx, t_map *map)
{
	mlx->txtr = (t_txtr *)malloc(sizeof(t_txtr));
	if (!mlx->txtr)
		return (NULL);
	mlx->txtr->map = map;
	mlx->txtr->map->img = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->map->img)
		return (NULL);
	mlx->txtr->map->img->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->map->img->data)
		return (NULL);
	mlx->txtr->clct = mlx_malloc_sprt();
	if (!mlx->txtr->clct)
		return (NULL);
	mlx->txtr->exit = mlx_malloc_sprt();
	if (!mlx->txtr->exit)
		return (NULL);
	mlx->txtr->skin = mlx_malloc_sprt();
	if (!mlx->txtr->skin)
		return (NULL);
	mlx->key = (t_key *)malloc(sizeof(t_key));
	if (!mlx->key)
		return (NULL);
	return (mlx);
}
