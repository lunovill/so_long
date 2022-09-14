/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:49:20 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/04 16:49:21 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_frame(int n)
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

int	mlx_opsprt(void *init, t_imgs *sprt, unsigned int id, size_t size)
{
	char	*index;

	if (!sprt->path)
		return (ft_error("textures:\t", "malloc error", NULL));
	index = ft_frame(size);
	sprt->path[id] = index[0];
	sprt->path[id + 1] = index[1];
	ft_free(index);
	sprt->frame = mlx_xpm_file_to_image(init, sprt->path,
			&sprt->width, &sprt->height);
	if (!sprt->frame)
		return (ft_error("textures:\ttexture not found : ",
				sprt->path, NULL));
	if (sprt->width != W_CASE || sprt->height != H_CASE)
		return (ft_error("textures:\ttexture bad size : ",
				sprt->path, NULL));
	return (0);
	free(init);
}

int	mlx_opmap(void *init, t_map *map, size_t size)

{
	if (!map->img->path)
		return (ft_error("textures:\t", "malloc error", NULL));
	map->frame = (void **)malloc(sizeof(void *) * size);
	while (size--)
	{
		if (size == BACKGROUND_SIZE - 1)
			map->img->path[BACKGROUND_ID] = '0';
		else
			map->img->path[BACKGROUND_ID] = size + 'A';
		map->frame[size] = mlx_xpm_file_to_image(init, map->img->path,
				&map->img->width, &map->img->height);
		if (!map->frame[size])
			return (ft_error("textures:\ttexture not found : ",
					map->img->path, NULL));
		if (map->img->width != W_CASE || map->img->height != H_CASE)
		{
			if (size)
				map->frame[size - 1] = NULL;
			return (ft_error("textures:\ttexture bad size : ",
					map->img->path, NULL));
		}
	}
	return (0);
}
