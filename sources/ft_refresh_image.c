/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:07:08 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/07 23:07:10 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_creat_background(t_data *data,
t_txtr *txtr, unsigned int x, unsigned int y)
{
	if ('0' <= txtr->map->coor[y][x]
		&& txtr->map->coor[y][x] <= '4')
	{
		txtr->map->img->data->img = txtr->map->frame[BACKGROUND_SIZE - 1];
		if (mlx_draw_image(data, txtr->map->img->data, x * W_CASE, y * H_CASE)
			== -1)
			return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	}
	if (txtr->map->coor[y][x] == '2')
	{
		if (mlx_draw_image(data, txtr->clct->data, x * W_CASE, y * H_CASE)
			== -1)
			return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	}
	else if (txtr->exit->x == x && txtr->exit->y == y)
	{
		if (mlx_draw_image(data, txtr->exit->data, x * W_CASE, y * H_CASE)
			== -1)
			return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	}
	return (0);
}

static int	ft_create_skin(t_data *data, t_txtr *txtr, t_imgs *skin)
{
	skin->data->img = skin->frame;
	if (ft_creat_background(data, txtr, skin->x, skin->y) == -1
		|| ft_creat_background(data, txtr, skin->x, skin->y - 1) == -1
		|| ft_creat_background(data, txtr, skin->x + 1, skin->y) == -1
		|| ft_creat_background(data, txtr, skin->x, skin->y + 1) == -1
		|| ft_creat_background(data, txtr, skin->x - 1, skin->y) == -1)
		return (-1);
	if (mlx_draw_image(data, skin->data, skin->x * W_CASE, skin->y * H_CASE)
		== 1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	return (0);
}

int	ft_refresh_image(t_mlx *mlx)
{
	mlx->txtr->map->img->data->img
		= mlx->txtr->map->frame[BACKGROUND_SIZE - 1];
	if (ft_create_skin(mlx->txtr->data, mlx->txtr, mlx->txtr->skin) == -1)
		return (ft_error("mlx:\t", "Image not refreshed", mlx));
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr->data->img, 0, 0);
	if (mlx->txtr->clct->x == 0 && mlx->txtr->exit->x == mlx->txtr->skin->x
		&& mlx->txtr->exit->y == mlx->txtr->skin->y)
		mlx_close(mlx, EXIT_SUCCESS);
	return (0);
}
