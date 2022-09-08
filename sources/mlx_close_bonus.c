/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:10:58 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:10:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_fmap(t_mlx *mlx, t_map *map, size_t size)
{
	if (!map)
		return ;
	ft_ftab(map->coor);
	while (size--)
		mlx_destroy_image(mlx->init, map->img->frame[size]);
	ft_free(map->img->frame);
	ft_free(map->img->data);
	ft_free(map->img);
	ft_free(map);
}

static void	ft_ftxtr(t_mlx *mlx, t_imgs *sprt, size_t size)
{
	if (!sprt)
		return ;
	while (size--)
		mlx_destroy_image(mlx->init, sprt->frame[size]);
	ft_free(sprt->frame);
	ft_free(sprt->data);
	ft_free(sprt);
}

int	mlx_close(t_mlx *mlx, int code_exit)
{
	ft_fmap(mlx, mlx->txtr->map, BACKGROUND_SIZE);
	ft_ftxtr(mlx, mlx->txtr->clct, CLCT_SIZE);
	ft_ftxtr(mlx, mlx->txtr->exit, EXIT_SIZE);
	ft_ftxtr(mlx, mlx->txtr->skin, SKIN_SIZE);
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
