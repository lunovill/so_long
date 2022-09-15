/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:52:09 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/15 00:04:03 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_fmap(t_mlx *mlx, t_map *map, size_t size)
{
	if (!map)
		return ;
	ft_ftab(map->coor);
	if (map->img->frame)
	{
		while (size--)
		{
			if (map->img->frame[size])
				mlx_destroy_image(mlx->init, map->img->frame[size]);
			else
				break ;
		}
		ft_free(map->img->frame);
	}
	if (map->img)
		ft_free(map->img->data);
	ft_free(map->img);
	ft_free(map);
}

static void	ft_ftxtr(t_mlx *mlx, t_imgs *sprt, size_t size)
{
	if (!sprt)
		return ;
	if (sprt->frame)
	{
		while (size--)
		{
			if (sprt->frame[size])
				mlx_destroy_image(mlx->init, sprt->frame[size]);
			else
				break ;
		}
		ft_free(sprt->frame);
	}
	ft_free(sprt->data);
	ft_free(sprt);
}

int	mlx_close(t_mlx *mlx, int code_exit)
{
	if (mlx->txtr)
	{
		ft_fmap(mlx, mlx->txtr->map, BKGD_SIZE);
		ft_ftxtr(mlx, mlx->txtr->clct, CLCT_SIZE);
		ft_ftxtr(mlx, mlx->txtr->exit, EXIT_SIZE);
		ft_ftxtr(mlx, mlx->txtr->skin, SKIN_SIZE);
	}
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->txtr && mlx->txtr->data && mlx->txtr->data->img)
		mlx_destroy_image(mlx->init, mlx->txtr->data->img);
	if (mlx->txtr)
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
