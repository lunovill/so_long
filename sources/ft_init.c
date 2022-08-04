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

static void	ft_find_coor(t_imgs *sprt, char **coor, char c)
{
	int		x;
	int		y;

	y = -1;
	while (coor[++y])
	{
		x = -1;
		while (coor[y][++x])
			if (coor[y][x] == c)
				break;
		if (coor[y][x] == c)
			break;
	}
	sprt->x = x;
	sprt->y = y;
}

static void	*ft_open_image_sprite(void *init, t_imgs sprt, unsigned int id, size_t size)
{
	ft_post(&sprt.data.post, (int)size);
	sprt.path[id] = sprt.data.post[0];
	sprt.path[id + 1] = sprt.data.post[1];
	return (mlx_xpm_file_to_image(init, sprt.path, &sprt.width, &sprt.height));
}

static void	**ft_open_image(t_mlx mlx, size_t size, int set)

{
	void	**frame;

	frame = (void **)malloc(sizeof(void *) * size);
	while (size--)
	{
		if (set == 0)
		{
			if (size == BACKGROUND_SIZE - 1)
				mlx.txtr.map.img.path[BACKGROUND_ID] = '0';
			else
				mlx.txtr.map.img.path[BACKGROUND_ID] = size + 'A';
			frame[size] = mlx_xpm_file_to_image(mlx.init, mlx.txtr.map.img.path, &mlx.txtr.map.img.width, &mlx.txtr.map.img.height);
		}
		else if (set == 2)
			frame[size] = ft_open_image_sprite(mlx.init, mlx.txtr.clct, COLLECTIBLE_ID, size);
		else if (set == 3)
			frame[size] = ft_open_image_sprite(mlx.init, mlx.txtr.exit, EXIT_ID, size);
		else if (set == 4)
			frame[size] = ft_open_image_sprite(mlx.init, mlx.txtr.skin, SKIN_ID, size);
		if (!frame[size])
			ft_error("textures:\t", "texture not found", &mlx);
	}
	return (frame);
}

void	ft_init(t_mlx *mlx, t_map *map)
{
	mlx->txtr.map = *map;
	mlx->txtr.map.img.data.post = NULL;
	mlx->txtr.map.img.path = ft_strdup(BACKGROUND);
	mlx->txtr.map.img.frame = ft_open_image(*mlx, BACKGROUND_SIZE, 0);
	free (mlx->txtr.map.img.path);
	mlx->txtr.clct.data.post = NULL;
	mlx->txtr.clct.path = ft_strdup(COLLECTIBLE);
	mlx->txtr.clct.frame = ft_open_image(*mlx, COLLECTIBLE_SIZE, 2);
	free (mlx->txtr.clct.path);
	ft_post(&mlx->txtr.clct.data.post, 0);
	mlx->txtr.exit.data.post = NULL;
	mlx->txtr.exit.path = ft_strdup(EXIT);
	mlx->txtr.exit.frame = ft_open_image(*mlx, EXIT_SIZE, 3);
	free (mlx->txtr.exit.path);
	ft_post(&mlx->txtr.exit.data.post, 0);
	ft_find_coor(&mlx->txtr.exit, mlx->txtr.map.coor, '3');
	mlx->txtr.skin.data.post = NULL;
	mlx->txtr.skin.path = ft_strdup(SKIN);
	mlx->txtr.skin.frame = ft_open_image(*mlx, SKIN_SIZE, 4);
	free (mlx->txtr.skin.path);
	ft_post(&mlx->txtr.skin.data.post, 16);
	ft_find_coor(&mlx->txtr.skin, mlx->txtr.map.coor, '4');
	mlx->speed = 0;
}
