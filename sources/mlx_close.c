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
	ft_free(mlx->txtr->map->img->frame);
	ft_free(mlx->txtr->map->img->data);
	ft_free(mlx->txtr->map->img);
	ft_free(mlx->txtr->map);
	size = CLCT_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->clct->frame[size]);
	ft_free(mlx->txtr->clct->frame);
	ft_free(mlx->txtr->clct->data);
	ft_free(mlx->txtr->clct);
	size = EXIT_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->exit->frame[size]);
	ft_free(mlx->txtr->exit->frame);
	ft_free(mlx->txtr->exit->data);
	ft_free(mlx->txtr->exit);
	size = SKIN_SIZE;
	while (size--)
		mlx_destroy_image(mlx->init, mlx->txtr->skin->frame[size]);
	ft_free(mlx->txtr->skin->frame);
	ft_free(mlx->txtr->skin->data);
	ft_free(mlx->txtr->skin);
}

int	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_ftab(mlx->txtr->map->coor);
	ft_ftxtr(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr->data->img)
		mlx_destroy_image(mlx->init, mlx->txtr->data->img);
	ft_free(mlx->txtr->data);
	mlx_destroy_display(mlx->init);
	ft_free(mlx->init);
	ft_free(mlx->txtr);
	ft_free(mlx->key);
	ft_free(mlx);
	if (code_exit == 318)
		code_exit = EXIT_SUCCESS;
	return (exit(code_exit), 0);
}
