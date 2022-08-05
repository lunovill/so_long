#include "so_long.h"

static int	ft_check_move(t_imgs skin, char **coor, int post)
{
	if (post == 0 && ft_isalpha(coor[skin.y - 1][skin.x]) == 1)
		return (-1);
	else if (post == 8 && ft_isalpha(coor[skin.y][skin.x + 1]) == 1)
		return (-1);
	else if (post == 16 && ft_isalpha(coor[skin.y + 1][skin.x]) == 1)
		return (-1);
	else if (post == 24 && ft_isalpha(coor[skin.y][skin.x - 1]) == 1)
		return (-1);
	return (0);
}

static int  ft_move(t_imgs *skin, char **coor, int move)
{
    if (ft_check_move(*skin, coor, move) == -1)
    {
        ft_post(&skin->data.post, move);
        return (-1);
    }
    else
        ft_post(&skin->data.post, move + 1);
    return (1);
}

int	mlx_key_press(int keycode, t_mlx *mlx)
{
	int	post;

	// ft_putnbr(keycode);
	// ft_putchar('\n');
	post = ft_atoi(mlx->txtr.skin.data.post);
	if (keycode == KEY_ESC)
		mlx_close(mlx, EXIT_SUCCESS);
	else if ((keycode == KEY_UP || keycode == KEY_ARROW_UP) && (post % 8) == 0)
        return (ft_move(&mlx->txtr.skin, mlx->txtr.map.coor, 0));
	else if ((keycode == KEY_RIGHT || keycode == KEY_ARROW_RIGHT) && (post % 8) == 0)
        return (ft_move(&mlx->txtr.skin, mlx->txtr.map.coor, 8));
	else if ((keycode == KEY_DOWN || keycode == KEY_ARROW_DOWN) && (post % 8) == 0)
        return (ft_move(&mlx->txtr.skin, mlx->txtr.map.coor, 16));
	else if ((keycode == KEY_LEFT || keycode == KEY_ARROW_LEFT) && (post % 8) == 0)
        return (ft_move(&mlx->txtr.skin, mlx->txtr.map.coor, 24));
    return (0);
}
