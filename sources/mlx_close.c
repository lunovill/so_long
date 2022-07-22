/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:52:09 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:52:26 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_ftab(mlx->txtr.map.coor);
	free(mlx->txtr.map.img.path);
	free(mlx->txtr.skin.path);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr.data.img)
		mlx_destroy_image(mlx->init, mlx->txtr.data.img);
	mlx_destroy_display(mlx->init);
	exit(code_exit);
}
