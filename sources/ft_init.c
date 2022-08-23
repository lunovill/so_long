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

static char *ft_frame(int n)
{
	char	frame[3];

	if (n < 10)
		frame[0] = '0';
	else
		frame[0] = n / 10 + '0';
	frame[1] = n % 10 + '0';
	frame[2] = '\0';
	return (ft_strdup(frame));
}

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
	sprt->x = x * W_CASE;
	sprt->y = y * H_CASE;
}

static void	*ft_open_image_sprite(void *init, t_imgs *sprt, unsigned int id, size_t size)
{
	char	*frame;

	frame = ft_frame(size);
	sprt->path[id] = frame[0];
	sprt->path[id + 1] = frame[1];
	free(frame);
	return (mlx_xpm_file_to_image(init, sprt->path, &sprt->width, &sprt->height));
}

static void	**ft_open_image(t_mlx *mlx, size_t size, int set)

{
	void	**frame;

	frame = (void **)malloc(sizeof(void *) * size);
	while (size--)
	{
		if (set == 0)
		{
			if (size == BACKGROUND_SIZE - 1)
				mlx->txtr->map->img->path[BACKGROUND_ID] = '0';
			else
				mlx->txtr->map->img->path[BACKGROUND_ID] = size + 'A';
			frame[size] = mlx_xpm_file_to_image(mlx->init, mlx->txtr->map->img->path, &mlx->txtr->map->img->width, &mlx->txtr->map->img->height);
		}
		else if (set == 2)
			frame[size] = ft_open_image_sprite(mlx->init, mlx->txtr->clct, CLCT_INDEX, size);
		else if (set == 3)
			frame[size] = ft_open_image_sprite(mlx->init, mlx->txtr->exit, EXIT_INDEX, size);
		else if (set == 4)
			frame[size] = ft_open_image_sprite(mlx->init, mlx->txtr->skin, SKIN_INDEX, size);
		if (!frame[size])
			ft_error("textures:\t", "texture not found", mlx);
	}
	return (frame);
}

int	ft_init(t_mlx *mlx, t_map *map)
{
	mlx->txtr = (t_txtr *)malloc(sizeof(t_txtr));
	if (!mlx->txtr)
		return (-1);
	mlx->txtr->map = map;
	mlx->txtr->map->img = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->map->img)
		return (-1);
	mlx->txtr->map->img->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->map->img->data)
		return (-1);
	mlx->txtr->map->img->path = ft_strdup(BACKGROUND);
	mlx->txtr->map->img->frame = ft_open_image(mlx, BACKGROUND_SIZE, 0);
	free (mlx->txtr->map->img->path);
	mlx->txtr->clct = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->clct)
		return (-1);
	mlx->txtr->clct->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->clct->data)
		return (-1);
	mlx->txtr->clct->index = 0;
	mlx->txtr->clct->path = ft_strdup(CLCT_PATH);
	mlx->txtr->clct->frame = ft_open_image(mlx, CLCT_SIZE, 2);
	free (mlx->txtr->clct->path);
	mlx->txtr->exit = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->exit)
		return (-1);
	mlx->txtr->exit->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->exit->data)
		return (-1);
	mlx->txtr->exit->index = 0;
	mlx->txtr->exit->path = ft_strdup(EXIT_PATH);
	mlx->txtr->exit->frame = ft_open_image(mlx, EXIT_SIZE, 3);
	free (mlx->txtr->exit->path);
	ft_find_coor(mlx->txtr->exit, mlx->txtr->map->coor, '3');
	mlx->txtr->skin = (t_imgs *)malloc(sizeof(t_imgs));
	if (!mlx->txtr->skin)
		return (-1);
	mlx->txtr->skin->data = (t_data *)malloc(sizeof(t_data));
	if (!mlx->txtr->skin->data)
		return (-1);
	mlx->txtr->skin->index = 16;
	mlx->txtr->skin->path = ft_strdup(SKIN_PATH);
	mlx->txtr->skin->frame = ft_open_image(mlx, SKIN_SIZE, 4);
	free (mlx->txtr->skin->path);
	ft_find_coor(mlx->txtr->skin, mlx->txtr->map->coor, '4');
	mlx->key = (t_key *)malloc(sizeof(t_key));
	if (!mlx->key)
		return (-1);
	mlx->key->up = 0;
	mlx->key->right = 0;
	mlx->key->down = 0;
	mlx->key->left = 0;
	mlx->speed = 0;
	return (0);
}

// static void ft_init_sprite(t_mlx *mlx, t_imgs *sprt, unsigned int size, int set)
// {
// 	sprt->frame = ft_open_image(*mlx, size, set);
// 	free (sprt->path);
// 	ft_find_coor(sprt, mlx->txtr->map->coor, set + '0');
// }

// void	ft_init(t_mlx *mlx, t_map *map)
// {
// 	mlx->txtr->map = *map;
// 	mlx->txtr->map->img->data->post = NULL;
// 	mlx->txtr->map->img->path = ft_strdup(BACKGROUND);
// 	mlx->txtr->map->img->frame = ft_open_image(*mlx, BACKGROUND_SIZE, 0);
// 	free (mlx->txtr->map->img->path);
// 	mlx->txtr->clct->data->post = NULL;
// 	mlx->txtr->clct->path = ft_strdup(CLCT_PATH);
// 	ft_init_sprite(mlx, &mlx->txtr->clct, CLCT_SIZE, 2);
// 	ft_post(&mlx->txtr->clct->data->post, 0);
// 	mlx->txtr->exit->data->post = NULL;
// 	mlx->txtr->exit->path = ft_strdup(EXIT_PATH);
// 	ft_init_sprite(mlx, &mlx->txtr->exit, EXIT_SIZE, 3);
// 	ft_post(&mlx->txtr->exit->data->post, 0);
// 	mlx->txtr->skin->data->post = NULL;
// 	mlx->txtr->skin->path = ft_strdup(SKIN_PATH);
// 	ft_init_sprite(mlx, &mlx->txtr->skin, SKIN_SIZE, 4);
// 	ft_post(&mlx->txtr->skin->data->post, 16);
// 	mlx->txtr->m_x = 0;
// 	mlx->txtr->m_x = 0;
// 	mlx->speed = 0;
// }
