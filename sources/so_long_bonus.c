/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:06:36 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:15:42 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	mlx_window(t_mlx *mlx)
{
	if (!mlx->win)
		return (ft_error("mlx:\t", "window doesn't open", mlx));
	mlx->txtr->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->data)
		return (ft_error("mlx:\t", "malloc error", mlx));
	mlx->txtr->data->img = mlx_new_image(mlx->init,
			mlx->txtr->map->width * W_CASE, mlx->txtr->map->height * H_CASE);
	if (!mlx->txtr->data->img)
		return (ft_error("mlx:\t", "map doesn't creat", mlx));
	mlx->txtr->data->addr = mlx_get_data_addr(mlx->txtr->data->img,
			&mlx->txtr->data->bpp, &mlx->txtr->data->sline,
			&mlx->txtr->data->endian);
	if (!mlx->txtr->data->addr)
		return (ft_error("mlx:\t", "image bad addr", mlx));
	ft_create_map(mlx->txtr->data, mlx->txtr->map);
	if (mlx_loop_hook(mlx->init, ft_refresh_image, mlx) == -1)
		return (ft_error("mlx:\t", "bad image", mlx));
	mlx_hook(mlx->win, KeyPress, KeyPressMask, mlx_key_press, mlx);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, mlx_key_release, mlx);
	mlx_hook(mlx->win, DestroyNotify, NoEventMask, mlx_close, mlx);
	mlx_loop(mlx->init);
	return (0);
}

int	so_long(t_map *map)
{
	t_mlx	*mlx;

	if (!map)
		return (ft_error("map:\t", "malloc error", NULL));
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_ftab(map->coor), ft_free(map),
			ft_error("mlx:\t", "malloc error", NULL));
	mlx->init = mlx_init();
	if (!mlx->init)
		return (ft_ftab(map->coor), ft_free(map), ft_free(mlx),
			ft_error("mlx:\t", "mlx doesn't initialize", NULL));
	mlx_get_screen_size(mlx->init, &mlx->wrslt, &mlx->hrslt);
	if ((unsigned int)mlx->wrslt < map->width * W_CASE
		|| (unsigned int)mlx->hrslt - 40 < map->height * H_CASE)
		return (ft_ftab(map->coor), ft_free(map),
			mlx_destroy_display(mlx->init), ft_free(mlx->init),
			ft_free(mlx), ft_error("map:\t", "map is too big.", NULL));
	ft_init(mlx, map);
	mlx->win = mlx_new_window(mlx->init, map->width * W_CASE,
			map->height * H_CASE, GAME_NAME);
	return (mlx_window(mlx));
}
