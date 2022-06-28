#include "mlx.h"
#include "libft.h"

typedef struct	s_mlx
{
	void *init;
	void *win;
}				t_mlx;

int	idle(t_mlx *mlx)
{
	void *image;
	int w;
	int h;
	char *path;

	path = (char *)malloc(sizeof(char) * 26);
	path = ft_strcpy(path, "./sprites/skin/run/00.xpm");
	while (path[20] != '8')
	{
		usleep(100000);
	image = mlx_xpm_file_to_image(mlx->init, path, &w, &h);
	mlx_put_image_to_window(mlx->init, mlx->win, image, 100, 100);
	path[20]++;
	}
	return (0);
}

int main()
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 200, 200, "Hello world!");
	mlx_loop_hook(mlx.init, idle, &mlx);
	mlx_loop(mlx.init);
	return (0);
}