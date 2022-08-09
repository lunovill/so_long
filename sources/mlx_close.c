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
		mlx_destroy_image(mlx->init, mlx->txtr->map->img->frame[size]);
	free(mlx->txtr->map->img->frame);
	free(mlx->txtr->map->img->data);
	free(mlx->txtr->map->img);
	free(mlx->txtr->map);
	size = COLLECTIBLE_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->clct->frame[size]);
	free(mlx->txtr->clct->frame);
	free(mlx->txtr->clct->data->post);
	free(mlx->txtr->clct->data);
	free(mlx->txtr->clct);
	size = EXIT_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->exit->frame[size]);
	free(mlx->txtr->exit->frame);
	free(mlx->txtr->exit->data->post);
	free(mlx->txtr->exit->data);
	free(mlx->txtr->exit);
	size = SKIN_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->skin->frame[size]);
	free(mlx->txtr->skin->frame);
	free(mlx->txtr->skin->data->post);
	free(mlx->txtr->skin->data);
	free(mlx->txtr->skin);
}

int	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_ftab(mlx->txtr->map->coor);
	ft_ftxtr(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr->data->img)
		mlx_destroy_image(mlx->init, mlx->txtr->data->img);
	free(mlx->txtr->data);
	mlx_destroy_display(mlx->init);
	free(mlx->txtr);
	free(mlx);
	if (code_exit == 318)
		code_exit = EXIT_SUCCESS;
	return (exit(code_exit), 0);
}
