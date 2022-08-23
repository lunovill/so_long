/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:47:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:47:49 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_clct(t_data *data, t_map *map, t_imgs *clct)
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
				mlx_draw_image(data, map->img->data, x * W_CASE, y * H_CASE);
				mlx_draw_image(data, clct->data, x * W_CASE, y * H_CASE);
				clct->x++;
			}
		}
	}
}

static void	ft_create_exit(t_data *data, t_map *map, t_imgs *exit)
{
	exit->data->img = exit->frame[exit->index];
	mlx_draw_image(data, map->img->data, exit->x, exit->y);
	mlx_draw_image(data, exit->data, exit->x, exit->y);
}

static void ft_creat_background(t_data *data, t_txtr *txtr, unsigned int x, unsigned int y)
{
	if ('0' <= txtr->map->coor[y / H_CASE][x / W_CASE] && txtr->map->coor[y / H_CASE][x / W_CASE] <= '4')
		txtr->map->img->data->img = txtr->map->img->frame[BACKGROUND_SIZE - 1];
	else
		txtr->map->img->data->img = txtr->map->img->frame[txtr->map->coor[y / H_CASE][x / W_CASE] - 'A'];
	mlx_draw_image(data, txtr->map->img->data, x, y);
	if (txtr->map->coor[y / H_CASE][x / W_CASE] == '2')
		mlx_draw_image(data, txtr->clct->data, x, y);
	else if (txtr->map->coor[y / H_CASE][x / W_CASE] == '3')
		mlx_draw_image(data, txtr->exit->data, x, y);
}

static void	ft_create_skin(t_data *data, t_txtr *txtr, t_imgs *skin)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	coef_x;
	unsigned int	coef_y;

	coef_x = skin->x % W_CASE;
	coef_y = skin->y % H_CASE;
	x = skin->x - (skin->x % W_CASE);
	y = skin->y - (skin->y % H_CASE);
	skin->data->img = skin->frame[skin->index];
	if ('0' <= txtr->map->coor[y / H_CASE][x / W_CASE] && txtr->map->coor[y / H_CASE][x / W_CASE] <= '4')
		txtr->map->img->data->img = txtr->map->img->frame[BACKGROUND_SIZE - 1];
	else
		txtr->map->img->data->img = txtr->map->img->frame[txtr->map->coor[y / H_CASE][x / W_CASE] - 'A'];
	ft_creat_background(data, txtr, x, y);
	if (txtr->map->coor[(txtr->skin->y + 40) / H_CASE][(txtr->skin->x + 40) / W_CASE] == '2' && 20 <= (txtr->skin->x + 40) % 80 && (txtr->skin->x + 40) % 80 <= 60 && 20 <= (txtr->skin->y + 40) % 80 && (txtr->skin->y + 40) % 80 <= 60)
		txtr->map->coor[(txtr->skin->y + 40) / H_CASE][(txtr->skin->x + 40) / W_CASE] = '0';
	if (0 < coef_x)
		ft_creat_background(data, txtr, x + W_CASE, y);
	if (0 < coef_y)
		ft_creat_background(data, txtr, x, y + H_CASE);
	if (0 < coef_x && 0 < coef_y)
		ft_creat_background(data, txtr, x + W_CASE, y + H_CASE);
	mlx_draw_image(data, skin->data, skin->x, skin->y);
}

int	ft_refresh_image(t_mlx *mlx)
{
	ft_next_frame(mlx);
	// if (mlx->key->up)
	// 	ft_creat_background(mlx->txtr->data, mlx->txtr, mlx->txtr->skin->x - (mlx->txtr->skin->x % W_CASE), mlx->txtr->skin->y - (mlx->txtr->skin->y % H_CASE) + H_CASE);
	// else if (mlx->key->right)
	// 	ft_creat_background(mlx->txtr->data, mlx->txtr, mlx->txtr->skin->x - (mlx->txtr->skin->x % W_CASE) - W_CASE, mlx->txtr->skin->y - (mlx->txtr->skin->y % H_CASE));
	// else if (mlx->key->down)
	// 	ft_creat_background(mlx->txtr->data, mlx->txtr, mlx->txtr->skin->x - (mlx->txtr->skin->x % W_CASE), mlx->txtr->skin->y - (mlx->txtr->skin->y % H_CASE) - H_CASE);
	// else if (mlx->key->left)
	// 	ft_creat_background(mlx->txtr->data, mlx->txtr, mlx->txtr->skin->x - (mlx->txtr->skin->x % W_CASE) + W_CASE, mlx->txtr->skin->y - (mlx->txtr->skin->y % H_CASE));
	mlx->txtr->map->img->data->img = mlx->txtr->map->img->frame[BACKGROUND_SIZE - 1];
	ft_create_clct(mlx->txtr->data, mlx->txtr->map, mlx->txtr->clct);
	ft_create_exit(mlx->txtr->data, mlx->txtr->map, mlx->txtr->exit);
	ft_create_skin(mlx->txtr->data, mlx->txtr, mlx->txtr->skin);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr->data->img, 0, 0);
	if (mlx->txtr->clct->x == 0 && mlx->txtr->map->coor[(mlx->txtr->skin->y + 40) / H_CASE][(mlx->txtr->skin->x + 40) / W_CASE] == '3')
		mlx_close(mlx, EXIT_SUCCESS);
	usleep(15000 * SPEED);
	return (0);
}
