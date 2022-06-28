#include "so_long.h"

static void	my_pixel_put(t_data *data, unsigned int x, unsigned int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->sline + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_pixel(t_data data, unsigned int x, unsigned int y)
{
	char	*src;

	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.sline, &data.endian);
	src = data.addr + (y * data.sline + x * (data.bpp / 8));
	return (*(unsigned int *)src);
}

void	mlx_draw_image(t_data img, t_data txtr, unsigned int row, unsigned int col)
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
				my_pixel_put(&img, (row * W_CASE) + x, (col * H_CASE) + y, pixel);
		}
	}
}

// static void	put_pixel_to_frame_buf(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->sline + x * (data->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

// static unsigned int	ft_get_pixel(int x, int y, void *img)
// {
// 	char	*src;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;

// 	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
// 	src = addr + (y * line_length + x * (bits_per_pixel / 8));
// 	return (*(unsigned int *)src);
// }

// void	mlx_draw_image(t_data *data, t_data txtr, int row, int col)
// {
// 	int	x;
// 	int	y;
// 	int	pixel;
// 	void *img = txtr.img;

// 	x = 0;
// 	y = 0;
// 	while (y < H_CASE)
// 	{
// 		x = 0;
// 		while (x < W_CASE)
// 		{
// 			pixel = ft_get_pixel(x, y, img);
// 			if (!(pixel & (0xFF << 24)))
// 				put_pixel_to_frame_buf(data, (col * W_CASE) + x,
// 					(row * H_CASE) + y, pixel);
// 			x++;
// 		}
// 		y++;
// 	}
// }