#include "so_long.h"

static void	mlx_close(t_mlx *mlx)
{
	ft_ftab(mlx->txtr.map.coor);
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_image(mlx->init, mlx->txtr.data.img);
	mlx_destroy_display(mlx->init);
	exit(EXIT_SUCCESS);
}

static int mlx_event(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		mlx_close(mlx);
	return (0);
}

// static close()
int     mlx_win(t_map map)
{
    t_mlx   mlx;

    mlx.init = mlx_init();
    mlx.win = mlx_new_window(mlx.init, map.width * W_CASE, map.height * H_CASE, GAME_NAME);
	mlx.txtr = ft_creat_image(mlx, map);
	// if (!mlx.img.data.img)
	// 	exit (0);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.txtr.data.img, 0, 0);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, &mlx_event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}