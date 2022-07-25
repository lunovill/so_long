/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:06:36 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 23:06:37 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	mlx_event(int keycode, t_mlx *mlx)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
		mlx_close(mlx, EXIT_SUCCESS);
	if (keycode == KEY_UP && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
	{
		if (ft_check_move(mlx->txtr.map.coor, 0) == -1)
		{
			ft_post(&mlx->txtr.skin.data.post, 0);
			return (-1);
		}
			ft_post(&mlx->txtr.skin.data.post, 1);
	}
	if (keycode == KEY_RIGHT && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
	{
		if (ft_check_move(mlx->txtr.map.coor, 8) == -1)
		{
			ft_post(&mlx->txtr.skin.data.post, 8);
			return (-1);
		}
			ft_post(&mlx->txtr.skin.data.post, 9);
	}
	if (keycode == KEY_DOWN && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
	{
		if (ft_check_move(mlx->txtr.map.coor, 16) == -1)
		{
			ft_post(&mlx->txtr.skin.data.post, 16);
			return (-1);
		}
			ft_post(&mlx->txtr.skin.data.post, 17);
	}
	if (keycode == KEY_LEFT && (ft_atoi(mlx->txtr.skin.data.post) % 8) == 0)
	{
		if (ft_check_move(mlx->txtr.map.coor, 24) == -1)
		{
			ft_post(&mlx->txtr.skin.data.post, 24);
			return (-1);
		}
			ft_post(&mlx->txtr.skin.data.post, 25);
	}
	return (0);
}

int	mlx_win(t_map map)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	ft_init(&mlx, &map);
	if (!mlx.init)
		return (ft_ftab(map.coor), ft_error("mlx: mlx doesn't initialize", NULL));
	mlx.win = mlx_new_window(mlx.init, map.width * W_CASE, map.height * H_CASE, GAME_NAME);
	if (!mlx.win)
		ft_error("mlx: window doesn't open", &mlx);
	mlx.txtr.data.img = mlx_new_image(mlx.init, mlx.txtr.map.width * W_CASE, mlx.txtr.map.height * H_CASE);
	if (!mlx.txtr.data.img)
		ft_error("mlx: map doesn't creat", &mlx);
	mlx_loop_hook(mlx.init, ft_creat_image, &mlx);
	mlx_hook(mlx.win, 02, 1L << 0, mlx_event, &mlx);
	//mlx_key_hook(mlx.win, mlx_event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
