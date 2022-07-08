#include "so_long.h"

void	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_ftab(mlx->txtr.map.coor);
	free(mlx->txtr.map.path);
	free(mlx->txtr.skin.path);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr.data.img)
		mlx_destroy_image(mlx->init, mlx->txtr.data.img);
	mlx_destroy_display(mlx->init);
	exit(code_exit);
}