#include "so_long.h"

static int	ft_check_move(char **coor, int post)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (coor[++y])
	{
		x = -1;
		while (coor[y][++x])
			if (coor[y][x] == '4')
				break ;
		if (coor[y][x] == '4')
			break ;
	}
	if (post == 0 && ft_isalpha(coor[y - 1][x]) == 1)
		return (-1);
	else if (post == 8 && ft_isalpha(coor[y][x + 1]) == 1)
		return (-1);
	else if (post == 16 && ft_isalpha(coor[y + 1][x]) == 1)
		return (-1);
	else if (post == 24 && ft_isalpha(coor[y][x - 1]) == 1)
		return (-1);
	return (0);
}

static int  ft_move(char **coor, char **post, int move)
{
    if (ft_check_move(coor, move) == -1)
    {
        ft_post(post, move);
        return (-1);
    }
    else
        ft_post(post, move + 1);
    return (1);
}

int	mlx_event(int keycode, t_mlx *mlx)
{
	// ft_putnbr(keycode);
	// ft_putchar('\n');
	if (keycode == KEY_ESC)
		mlx_close(mlx, EXIT_SUCCESS);
	else if (keycode == KEY_UP && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
        return (ft_move(mlx->txtr.map.coor, &mlx->txtr.skin.data.post, 0));
	else if (keycode == KEY_RIGHT && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
        return (ft_move(mlx->txtr.map.coor, &mlx->txtr.skin.data.post, 8));
	else if (keycode == KEY_DOWN && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
        return (ft_move(mlx->txtr.map.coor, &mlx->txtr.skin.data.post, 16));
	else if (keycode == KEY_LEFT && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
        return (ft_move(mlx->txtr.map.coor, &mlx->txtr.skin.data.post, 24));
    return (0);
}
