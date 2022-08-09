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

static unsigned int	ft_move_x(char *post)
{
	int	x;

	if (!post)
		return (0);
	x = ft_atoi(post);
	if (7 < x && x < 16)
		return (x % 8 * 10);
	if (23 < x)
		return (-(x % 8 * 10));
	return (0);
}

static unsigned int	ft_move_y(char *post)
{
	int	y;

	if (!post)
		return (0);
	y = ft_atoi(post);
	if (15 < y && y < 24)
		return (y % 8 * 10);
	if (y < 8)
		return (-(y % 8 * 10));
	return (0);
}

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
				my_pixel_put(img, (row * W_CASE) + x + ft_move_x(txtr->post), (col * H_CASE) + y + ft_move_y(txtr->post), pixel);
		}
	}
}
