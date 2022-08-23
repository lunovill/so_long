/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:53:27 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:53:29 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_pixel_put(t_data *data, unsigned int x, unsigned int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->sline + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_pixel(t_data *data, unsigned int x, unsigned int y)
{
	char	*src;

	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->sline, &data->endian);
	src = data->addr + (y * data->sline + x * (data->bpp / 8));
	return (*(unsigned int *)src);
}

void	mlx_draw_image(t_data *img, t_data *txtr, unsigned int row, unsigned int col)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pixel;

	y = -1;
	while (++y < H_CASE)
	{
		x = -1;
		while (++x < W_CASE)
		{
			pixel = mlx_get_pixel(txtr, x, y);
			if (!(pixel & (0xFF << 24)))
				my_pixel_put(img, row + x, col + y, pixel);
		}
	}
}
