#include "mlx.h"

int main()
{
	void *mlx;
	void *mlx_win;
	void *image;
	int w;
	int h;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	image = mlx_xpm_file_to_image(mlx, "./minilibx/test/open.xpm", &w, &h);
	mlx_put_image_to_window(mlx, mlx_win, image, 100, 100);
	mlx_loop(mlx);
	return (0);
}
