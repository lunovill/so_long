#include "so_long.h"

static int mlx_event(int keycode, t_mlx *mlx)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	ft_putnbr(mlx->txtr.skin.data.index);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
		mlx_close(mlx, EXIT_SUCCESS);
	if (keycode == KEY_DOWN && (mlx->txtr.skin.data.index % 4) == 0)
			mlx->txtr.skin.data.index = 13;
	return (0);
}

int     mlx_win(t_map map)
{
    t_mlx   mlx;

	ft_init_txtr(&mlx.txtr, &map);
    mlx.init = mlx_init();
	if (!mlx.init)
		return (ft_ftab(map.coor), ft_error("mlx: mlx doesn't initialize", NULL));
    mlx.win = mlx_new_window(mlx.init, map.width * W_CASE, map.height * H_CASE, GAME_NAME);
	if (!mlx.win)
		ft_error("mlx: window doesn't open", &mlx);
	mlx.txtr = ft_creat_image(mlx, map, mlx.txtr);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.txtr.data.img, 0, 0);
	mlx_key_hook(mlx.win, mlx_event, &mlx);
	// mlx_hook(mlx.win, KeyPress, KeyPressMask, &mlx_event, &mlx);
	usleep(100000);
	mlx_loop(mlx.init);
	return (0);
}