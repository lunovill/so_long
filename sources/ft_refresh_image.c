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

static void	ft_creat_sprite(t_data data, t_imgs sprt, unsigned int x, unsigned int y)
{
	int	tmp;

	tmp = ft_atoi(sprt.data.post);
	sprt.data.img = sprt.frame[tmp];
	ft_post(&sprt.data.post, 0);
	mlx_draw_image(data, sprt.data, x, y);
	ft_post(&sprt.data.post, tmp);
}

static void	ft_creat_move(t_data data, t_txtr txtr, unsigned int x, unsigned int y)
{
	mlx_draw_image(data, txtr.map.img.data, x, y);
	if (txtr.map.coor[y][x] == '2')
		ft_creat_sprite(data, txtr.clct, x, y);
	else if (txtr.exit.x == x && txtr.exit.y == y)
		ft_creat_sprite(data, txtr.exit, x, y);
}

static void	ft_creat_skin(t_data data, t_txtr txtr, unsigned int x, unsigned int y)
{
	int post;

	post = ft_atoi(txtr.skin.data.post);
	if (txtr.exit.x == x && txtr.exit.y == y)
		ft_creat_sprite(data, txtr.exit, x, y);
	if (post != 0)
	{
		if (0 < post && post <= 7)
			ft_creat_move(data, txtr, x, y - 1);
		else if (8 < post && post <= 15)
			ft_creat_move(data, txtr, x + 1, y);
		else if (16 < post && post <= 23)
			ft_creat_move(data, txtr, x, y + 1);
		else if (24 < post)
			ft_creat_move(data, txtr, x - 1, y);
	}
	txtr.skin.data.img = txtr.skin.frame[post];
	mlx_draw_image(data, txtr.skin.data, x, y);
}

int	ft_refresh_image(t_mlx *mlx)
{
	unsigned int	x;
	unsigned int	y;

	mlx->txtr.map.img.data.img = mlx->txtr.map.img.frame[BACKGROUND_SIZE - 1];
	mlx->txtr.clct.x = 0;
	y = -1;
	while (++y < mlx->txtr.map.height)
	{
		x = -1;
		while (++x < mlx->txtr.map.width)
		{

			if (mlx->txtr.map.coor[y][x] == '2')
			{
				mlx_draw_image(mlx->txtr.data, mlx->txtr.map.img.data, x, y);
				ft_creat_sprite(mlx->txtr.data, mlx->txtr.clct, x, y);
				mlx->txtr.clct.x++;
			}
		}
	}
	mlx_draw_image(mlx->txtr.data, mlx->txtr.map.img.data, mlx->txtr.exit.x, mlx->txtr.exit.y);
	ft_creat_sprite(mlx->txtr.data, mlx->txtr.exit, mlx->txtr.exit.x, mlx->txtr.exit.y);
	mlx_draw_image(mlx->txtr.data, mlx->txtr.map.img.data, mlx->txtr.skin.x, mlx->txtr.skin.y);
	ft_creat_skin(mlx->txtr.data, mlx->txtr, mlx->txtr.skin.x, mlx->txtr.skin.y);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr.data.img, 0, 0);
	if (mlx->txtr.clct.x == 0 && mlx->txtr.skin.x == mlx->txtr.exit.x && mlx->txtr.skin.y == mlx->txtr.exit. y)
		mlx_close(mlx, EXIT_SUCCESS);
	usleep(10000 * SPEED);
	ft_next_frame(mlx);
	return (0);
}
