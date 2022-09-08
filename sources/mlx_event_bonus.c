/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 02:14:26 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 19:06:39 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mlx_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		mlx_close(mlx, EXIT_SUCCESS);
	else if (mlx->key->up == 1 || mlx->key->right == 1
		|| mlx->key->down == 1 || mlx->key->left == 1)
		return (1);
	else if (keycode == KEY_UP || keycode == KEY_ARROW_UP)
		mlx->key->up = 1;
	else if (keycode == KEY_RIGHT || keycode == KEY_ARROW_RIGHT)
		mlx->key->right = 1;
	else if (keycode == KEY_DOWN || keycode == KEY_ARROW_DOWN)
		mlx->key->down = 1;
	else if (keycode == KEY_LEFT || keycode == KEY_ARROW_LEFT)
		mlx->key->left = 1;
	return (0);
}

int	mlx_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_UP || keycode == KEY_ARROW_UP)
		mlx->key->up = 2;
	else if (keycode == KEY_RIGHT || keycode == KEY_ARROW_RIGHT)
		mlx->key->right = 2;
	else if (keycode == KEY_DOWN || keycode == KEY_ARROW_DOWN)
		mlx->key->down = 2;
	else if (keycode == KEY_LEFT || keycode == KEY_ARROW_LEFT)
		mlx->key->left = 2;
	return (0);
}
