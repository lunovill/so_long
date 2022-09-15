/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_image_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:09:04 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:09:06 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_crt_clct(t_data *data, t_map *map, t_imgs *clct)
{
	unsigned int	x;
	unsigned int	y;

	clct->data->img = clct->frame[clct->index];
	clct->x = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->coor[y][x] == '2')
			{
				if (mlx_draw_image(data, map->img->data, x * W_CASE, y * H_CASE)
					== -1)
					return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
				if (mlx_draw_image(data, clct->data, x * W_CASE, y * H_CASE)
					== -1)
					return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
				clct->x++;
			}
		}
	}
	return (0);
}

static int	ft_crt_exit(t_data *data, t_map *map, t_imgs *exit)
{
	exit->data->img = exit->frame[exit->index];
	if (mlx_draw_image(data, map->img->data, exit->x, exit->y)
		== -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	if (mlx_draw_image(data, exit->data, exit->x, exit->y)
		== -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	return (0);
}

static int	ft_bkgd(t_data *data,
t_txtr *txtr, unsigned int x, unsigned int y)
{
	if ('0' <= txtr->map->coor[y / H_CASE][x / W_CASE]
		&& txtr->map->coor[y / H_CASE][x / W_CASE] <= '4')
		txtr->map->img->data->img = txtr->map->img->frame[BKGD_SIZE - 1];
	else
		txtr->map->img->data->img = txtr->map->img->frame
		[txtr->map->coor[y / H_CASE][x / W_CASE] - 'A'];
	if (mlx_draw_image(data, txtr->map->img->data, x, y) == -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	if (txtr->map->coor[y / H_CASE][x / W_CASE] == '2')
	{
		if (mlx_draw_image(data, txtr->clct->data, x, y) == -1)
			return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	}
	else if (txtr->map->coor[y / H_CASE][x / W_CASE] == '3')
	{
		if (mlx_draw_image(data, txtr->exit->data, x, y) == -1)
			return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	}
	return (0);
}

static int	ft_crt_skin(t_data *data, t_txtr *txtr, t_imgs *skin)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	coef_x;
	unsigned int	coef_y;

	coef_x = skin->x % W_CASE;
	coef_y = skin->y % H_CASE;
	x = skin->x - coef_x;
	y = skin->y - coef_y;
	skin->data->img = skin->frame[skin->index];
	if (ft_bkgd(data, txtr, x, y) == -1)
		return (-1);
	if (txtr->map->coor[txtr->skin->y / H_CASE][txtr->skin->x / W_CASE] == '2'
		&& 20 <= coef_x && coef_x <= 60 && 20 <= coef_y && coef_y <= 60)
		txtr->map->coor[txtr->skin->y / H_CASE][txtr->skin->x / W_CASE] = '0';
	if (ft_bkgd(data, txtr, x, y - H_CASE) == -1 || ft_bkgd(data, txtr,
			x + W_CASE, y) == -1 || ft_bkgd(data, txtr, x, y + H_CASE) == -1
		|| ft_bkgd(data, txtr, x - W_CASE, y) == -1 || ft_bkgd(data, txtr, x
			- W_CASE, y - H_CASE) == -1 || ft_bkgd(data, txtr, x + W_CASE, y
			- H_CASE) == -1 || ft_bkgd(data, txtr, x + W_CASE, y + H_CASE) == -1
		|| ft_bkgd(data, txtr, x - W_CASE, y + H_CASE) == -1)
		return (-1);
	if (mlx_draw_image(data, skin->data, skin->x - 40, skin->y - 40) == -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	return (0);
}

int	ft_refresh_image(t_mlx *mlx)
{
	char	*s;

	ft_next_frame(mlx);
	mlx->txtr->map->img->data->img = mlx->txtr->map->img->frame[BKGD_SIZE - 1];
	if (ft_crt_clct(mlx->txtr->data, mlx->txtr->map, mlx->txtr->clct) == -1
		|| ft_crt_exit(mlx->txtr->data, mlx->txtr->map, mlx->txtr->exit) == -1
		|| ft_crt_skin(mlx->txtr->data, mlx->txtr, mlx->txtr->skin) == -1)
		return (ft_error("mlx:\t", "image not refreshed", mlx));
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr->data->img, 0, 0);
	s = ft_strjoinf("move : ", ft_uitoa(mlx->count / 80), 2);
	if (!s)
		return (ft_error("mlx:\t", "move not refreshed", mlx));
	mlx_string_put(mlx->init, mlx->win, (mlx->txtr->map->width * W_CASE)
		- ((mlx->txtr->map->width * W_CASE) / 2) - ((ft_strlen(s) / 2) * 10),
		H_CASE / 2, 0x00FFFFFF, s);
	ft_free(s);
	if (mlx->txtr->clct->x == 0 && mlx->txtr->map->coor[mlx->txtr->skin->y
			/ H_CASE][mlx->txtr->skin->x / W_CASE] == '3')
		mlx_close(mlx, EXIT_SUCCESS);
	usleep(50000 / SPEED);
	return (0);
}
