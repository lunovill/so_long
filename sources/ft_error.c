#include "so_long.h"

int	ft_error(const char *error, t_mlx *mlx)
{
	ft_putstr_fd("so_long: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	if (mlx)
		mlx_close(mlx, EXIT_FAILURE);
	return (-1);
}
