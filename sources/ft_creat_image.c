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

static void	ft_move_map(t_map *map, int post)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (map->coor[++y])
	{
		x = -1;
		while (map->coor[y][++x])
			if (map->coor[y][x] == '4')
				break ;
		if (map->coor[y][x] == '4')
			break ;
	}
	if (post == 7)
		map->coor[y - 1][x] = '4';
	else if (post == 15)
		map->coor[y][x + 1] = '4';
	else if (post == 23)
		map->coor[y + 1][x] = '4';
	else if (post == 31)
		map->coor[y][x - 1] = '4';
	map->coor[y][x] = '0';
}

static void	ft_creat_map(t_data data, t_map map)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
		{
			if ('0' <= map.coor[y][x] && map.coor[y][x] <= '4')
				map.img.data.img = map.img.xpm[BACKGROUND_SIZE - 1];
			else
				map.img.data.img = map.img.xpm[map.coor[y][x] - 'A'];
			mlx_draw_image(data, map.img.data, x, y);
		}
	}
}

static void	ft_creat_sprite(t_data data, t_txtr txtr)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < txtr.map.height)
	{
		x = -1;
		while (++x < txtr.map.width)
		{
			if (txtr.map.coor[y][x] == '4')
			{
				txtr.skin.data.img = txtr.skin.xpm[ft_atoi(txtr.skin.data.post)];
				mlx_draw_image(data, txtr.skin.data, x, y);
			}
		}
	}
}

int	ft_creat_image(t_mlx *mlx)
{
	mlx->txtr.data.addr = mlx_get_data_addr(mlx->txtr.data.img, &mlx->txtr.data.bpp, &mlx->txtr.data.sline, &mlx->txtr.data.endian);
	ft_creat_map(mlx->txtr.data, mlx->txtr.map);
	ft_creat_sprite(mlx->txtr.data, mlx->txtr);
	if ((ft_atoi(mlx->txtr.skin.data.post) % 8) == 7)
	{
		ft_move_map(&mlx->txtr.map, ft_atoi(mlx->txtr.skin.data.post));
		ft_post(&mlx->txtr.skin.data.post, ft_atoi(mlx->txtr.skin.data.post) - 7);
	}
	else if ((ft_atoi(mlx->txtr.skin.data.post) % 8) != 0)
		ft_post(&mlx->txtr.skin.data.post, ft_atoi(mlx->txtr.skin.data.post) + 1);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->txtr.data.img, 0, 0);
	usleep(25000);
	return (0);
}
