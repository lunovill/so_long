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

static void	ft_ftxtr(t_mlx *mlx)
{
	size_t	size;

	size = BACKGROUND_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr.map.img.frame[size]);
	free(mlx->txtr.map.img.frame);
	size = COLLECTIBLE_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr.clct.frame[size]);
	free(mlx->txtr.clct.frame);
	size = EXIT_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr.exit.frame[size]);
	free(mlx->txtr.exit.frame);
	size = SKIN_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr.skin.frame[size]);
	free(mlx->txtr.skin.frame);
}

int	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_ftab(mlx->txtr.map.coor);
	ft_ftxtr(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr.data.img)
		mlx_destroy_image(mlx->init, mlx->txtr.data.img);
	mlx_destroy_display(mlx->init);
	if (code_exit == 318)
		code_exit = EXIT_SUCCESS;
	return (exit(code_exit), 0);
}
