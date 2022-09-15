/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:12:18 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 19:06:47 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_close(mlx, EXIT_SUCCESS);
	else if (mlx->key->up == 1 || mlx->key->right == 1
		|| mlx->key->down == 1 || mlx->key->left == 1)
		return (1);
	else if (keycode == XK_w)
		ft_next_frame(mlx, 'N');
	else if (keycode == XK_d)
		ft_next_frame(mlx, 'E');
	else if (keycode == XK_s)
		ft_next_frame(mlx, 'S');
	else if (keycode == XK_a)
		ft_next_frame(mlx, 'W');
	return (0);
}
