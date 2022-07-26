/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:47:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:47:49 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_creat_collectible(t_data data, t_imgs clct, unsigned int x, unsigned int y)
{
	int	tmp;

	tmp = ft_atoi(clct.data.post);
	clct.data.img = clct.xpm[tmp];
	ft_post(&clct.data.post, 0);
	mlx_draw_image(data, clct.data, x, y);
	ft_post(&clct.data.post, tmp);
}

static void	ft_creat_skin(t_data data, t_txtr txtr, unsigned int x, unsigned int y)
{
	int post;

	post = ft_atoi(txtr.skin.data.post);
	//si collectible sur prochaine case, redessiner ??
	if (post != 0)
	{
		if (0 < post && post <= 7)
			mlx_draw_image(data, txtr.map.img.data, x, y - 1);
		else if (8 < post && post <= 15)
			mlx_draw_image(data, txtr.map.img.data, x + 1, y);
		else if (16 < post && post <= 23)
			mlx_draw_image(data, txtr.map.img.data, x, y + 1);
		else if (24 < post)
			mlx_draw_image(data, txtr.map.img.data, x - 1, y);
	}
	txtr.skin.data.img = txtr.skin.xpm[post];
	mlx_draw_image(data, txtr.skin.data, x, y);
}

int	ft_refresh_image(t_mlx *mlx)
{
	unsigned int	x;
	unsigned int	y;

	mlx->txtr.map.img.data.img = mlx->txtr.map.img.xpm[BACKGROUND_SIZE - 1];
	y = -1;
	while (++y < mlx->txtr.map.height)
	{
		x = -1;
		while (++x < mlx->txtr.map.width)
		{

			if (mlx->txtr.map.coor[y][x] == '2')
			{
				mlx_draw_image(mlx->txtr.data, mlx->txtr.map.img.data, x, y);
				ft_creat_collectible(mlx->txtr.data, mlx->txtr.clct, x, y);
			}
			else if (mlx->txtr.map.coor[y][x] == '4')
			{
				mlx_draw_image(mlx->txtr.data, mlx->txtr.map.img.data, x, y);
				ft_creat_skin(mlx->txtr.data, mlx->txtr, x, y);
			}
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr.data.img, 0, 0);
	usleep(10000 * SPEED);
	ft_next_frame(mlx);
	return (0);
}
