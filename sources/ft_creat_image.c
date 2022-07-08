#include "so_long.h"

static void	ft_creat_map(t_mlx	mlx, t_data data, t_map map)
{
	t_sprt			txtr;
	unsigned int    x;
	unsigned int    y;

	y = -1;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
		{
			if ('2' <= map.coor[y][x] && map.coor[y][x] <= '4')
				map.path[BACKGROUND_ID] = '0';
			else
				map.path[BACKGROUND_ID] = map.coor[y][x];
			txtr.data.img = mlx_xpm_file_to_image(mlx.init, map.path, &txtr.width, &txtr.height);
			if (!txtr.data.img)
				ft_error("textures: background not found", &mlx);
			txtr.data.index = 0;
			mlx_draw_image(data, txtr.data, x, y);
		}
	}
}

static void	ft_creat_sprite(t_mlx mlx, t_data data, t_txtr img)
{
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
				img.skin.path[SKIN_ID] = img.skin.data.index + 65;
	ft_printf("%s\n", img.skin.path);
				img.skin.data.img = mlx_xpm_file_to_image(mlx.init, img.skin.path, &img.skin.width, &img.skin.height);
				if (!img.skin.data.img)
					ft_error("textures: skin not found", &mlx);
				mlx_draw_image(data, img.skin.data, x, y);
			}
		}
	}
}

t_txtr	ft_creat_image(t_mlx mlx, t_map map, t_txtr txtr)
{
	txtr.map = map;
	txtr.data.img = mlx_new_image(mlx.init, txtr.map.width * W_CASE, txtr.map.height * H_CASE);
	if (!txtr.data.img)
		ft_error("mlx: map doesn't creat", &mlx);
	txtr.data.addr = mlx_get_data_addr(txtr.data.img, &txtr.data.bpp, &txtr.data.sline, &txtr.data.endian);
	ft_creat_map(mlx, txtr.data, txtr.map);
	ft_creat_sprite(mlx, txtr.data, txtr);
	if (mlx.txtr.skin.data.index % 4 != 0)
		mlx.txtr.skin.data.index++;
	else
		mlx.txtr.skin.data.index -= 4;
	return (txtr);
}
