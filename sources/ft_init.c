/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:49:12 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:49:13 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**ft_open_image(t_mlx mlx, size_t size, int set)

{
	void	**xpm;

	xpm = (void **)malloc(sizeof(void *) * size);
	while (size--)
	{
		if (set == 0)
		{
			if (size == BACKGROUND_SIZE - 1)
				mlx.txtr.map.img.path[BACKGROUND_ID] = '0';
			else
				mlx.txtr.map.img.path[BACKGROUND_ID] = size + 'A';
			xpm[size] = mlx_xpm_file_to_image(mlx.init, mlx.txtr.map.img.path, &mlx.txtr.map.img.width, &mlx.txtr.map.img.height);
		}
		else if (set == 4)
		{
			ft_post(&mlx.txtr.skin.data.post, (int)size);
			mlx.txtr.skin.path[SKIN_ID] = mlx.txtr.skin.data.post[0];
			mlx.txtr.skin.path[SKIN_ID + 1] = mlx.txtr.skin.data.post[1];
			xpm[size] = mlx_xpm_file_to_image(mlx.init, mlx.txtr.skin.path, &mlx.txtr.skin.width, &mlx.txtr.skin.height);
		}
		else if (set == 2)
		{
			ft_post(&mlx.txtr.clct.data.post, (int)size);
			mlx.txtr.clct.path[COLLECTIBLE_ID] = mlx.txtr.clct.data.post[0];
			mlx.txtr.clct.path[COLLECTIBLE_ID + 1] = mlx.txtr.clct.data.post[1];
			xpm[size] = mlx_xpm_file_to_image(mlx.init, mlx.txtr.clct.path, &mlx.txtr.clct.width, &mlx.txtr.clct.height);
		}
		if (!xpm[size])
			ft_error("textures:\t", "texture not found", &mlx);
	}
	return (xpm);
}

void	ft_init(t_mlx *mlx, t_map *map)
{
	mlx->txtr.map = *map;
	mlx->txtr.map.img.data.post = NULL;
	mlx->txtr.map.img.path = ft_strdup(BACKGROUND);
	mlx->txtr.map.img.xpm = ft_open_image(*mlx, BACKGROUND_SIZE, 0);
	free (mlx->txtr.map.img.path);
	mlx->txtr.skin.data.post = NULL;
	mlx->txtr.skin.path = ft_strdup(SKIN);
	mlx->txtr.skin.xpm = ft_open_image(*mlx, SKIN_SIZE, 4);
	free (mlx->txtr.skin.path);
	ft_post(&mlx->txtr.skin.data.post, 16);
	mlx->txtr.clct.data.post = NULL;
	mlx->txtr.clct.path = ft_strdup(COLLECTIBLE);
	mlx->txtr.clct.xpm = ft_open_image(*mlx, COLLECTIBLE_SIZE, 2);
	free (mlx->txtr.clct.path);
	ft_post(&mlx->txtr.clct.data.post, 0);
//	mlx->txtr.clct.data.post = ft_strdup("");
//	mlx->txtr.exit.path = ft_strdup(EXIT);
//	mlx->txtr.exit.data.post = ft_strdup("");
	mlx->speed = 0;
}
