#include "so_long.h"

static void	ft_creat_map(t_mlx	mlx, t_data data, t_map map)
{
	t_sprt			txtr;
	char			*path;
	unsigned int    x;
    unsigned int    y;

	path = ft_strdup(BACKGROUND);
    y = -1;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
		{
			if ('2' <= map.coor[y][x] && map.coor[y][x] <= '4')
				path[BACKGROUND_ID] = '0';
			else
				path[BACKGROUND_ID] = map.coor[y][x];
			txtr.data.img = mlx_xpm_file_to_image(mlx.init, path, &txtr.width, &txtr.height);
			mlx_draw_image(data, txtr.data, x, y);
		}
	}
	free(path);
}

static void	ft_creat_sprite(t_mlx mlx, t_data data, t_img img)
{
	char			*path;
	unsigned int    x;
    unsigned int    y;

	y = -1;
	while (++y < img.map.height)
	{
		x = -1;
		while (++x < img.map.width)
		{
			if (img.map.coor[y][x] == '4')
			{
				path = ft_strdup(SKIN);
				path[SKIN_ID] = 'S';
				img.skin.data.img = mlx_xpm_file_to_image(mlx.init, path, &img.skin.width, &img.skin.height);
				mlx_draw_image(data, img.skin.data, x, y);
				free(path);
			}
		}
	}
}

t_img	ft_creat_image(t_mlx mlx, t_map map)
{
	t_img	img;

	img.map = map;
	img.data.img = mlx_new_image(mlx.init, img.map.width * W_CASE, img.map.height * H_CASE);
	img.data.addr = mlx_get_data_addr(img.data.img, &img.data.bpp, &img.data.sline, &img.data.endian);
	ft_creat_map(mlx, img.data, img.map);
	ft_creat_sprite(mlx, img.data, img);
	return (img);
}