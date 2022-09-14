/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:37:10 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/03 23:37:12 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_create_clct(t_data *data, t_map *map, t_imgs *clct)
{
	unsigned int	x;
	unsigned int	y;

	clct->data->img = clct->frame;
	clct->x = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->coor[y][x] == '2')
			{
				if (mlx_draw_image(data, clct->data, x * W_CASE, y * H_CASE)
					== -1)
					return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
				clct->x++;
			}
		}
	}
	return (0);
}

static int	ft_create_exit(t_data *data, t_map *map, t_imgs *exit)
{
	exit->data->img = exit->frame;
	if (mlx_draw_image(data, map->img->data, exit->x * W_CASE, exit->y * H_CASE)
		== -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	if (mlx_draw_image(data, exit->data, exit->x * W_CASE, exit->y * H_CASE)
		== -1)
		return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
	return (0);
}

int	ft_create_map(t_data *data, t_map *map, t_txtr *txtr)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if ('0' <= map->coor[y][x] && map->coor[y][x] <= '4')
				map->img->data->img = map->frame[BACKGROUND_SIZE - 1];
			else
				map->img->data->img = map->frame[map->coor[y][x] - 'A'];
			if (mlx_draw_image(data, map->img->data, x * W_CASE, y * H_CASE)
				== -1)
				return (ft_error("mlx:\t", "mlx_draw_image failed", NULL));
		}
	}
	map->img->data->img = map->frame[BACKGROUND_SIZE - 1];
	if (ft_create_clct(data, map, txtr->clct) == -1)
		return (-1);
	if (ft_create_exit(data, map, txtr->exit) == -1)
		return (-1);
	return (0);
}
