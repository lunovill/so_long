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
	if (keycode == XK_Escape)
		mlx_close(mlx, EXIT_SUCCESS);
	else if (mlx->key->up == 1 || mlx->key->right == 1
		|| mlx->key->down == 1 || mlx->key->left == 1)
		return (1);
	else if (keycode == XK_w || keycode == XK_Up)
		mlx->key->up = 1;
	else if (keycode == XK_d || keycode == XK_Right)
		mlx->key->right = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		mlx->key->down = 1;
	else if (keycode == XK_a || keycode == XK_Left)
		mlx->key->left = 1;
	return (0);
}

int	mlx_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_Up)
		mlx->key->up = 2;
	else if (keycode == XK_d || keycode == XK_Right)
		mlx->key->right = 2;
	else if (keycode == XK_s || keycode == XK_Down)
		mlx->key->down = 2;
	else if (keycode == XK_a || keycode == XK_Left)
		mlx->key->left = 2;
	return (0);
}
