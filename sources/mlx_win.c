#include "so_long.h"

// static close()
int     mlx_win(t_map map)
{
    t_mlx   mlx;
	t_img	img;

    mlx.init = mlx_init();
    mlx.win = mlx_new_window(mlx.init, map.width * W_CASE, map.height * H_CASE, GAME_NAME);
	img = ft_creat_image(mlx, map);
	// if (!img.data.img)
	// 	exit (0);
	mlx_put_image_to_window(mlx.init, mlx.win, img.data.img, 0, 0);
	mlx_loop(mlx.init);
	return (0);
}