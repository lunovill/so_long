/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_xpm_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:49:20 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:13:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	*mlx_opsprt(void *init, t_imgs *sprt, unsigned int id, size_t size)
{
	char	*frame;
	void	*img;

	frame = ft_frame(size);
	sprt->path[id] = frame[0];
	sprt->path[id + 1] = frame[1];
	ft_free(frame);
	img = mlx_xpm_file_to_image(init, sprt->path, &sprt->width, &sprt->height);
	if (!img)
		return (ft_error("textures:\ttexture not found : ",
				sprt->path, NULL), NULL);
	if (sprt->width != W_CASE || sprt->height != H_CASE)
		return (ft_error("textures:\ttexture bad size : ",
				sprt->path, NULL), NULL);
	return (img);
}

void	**mlx_opxpm(t_mlx *mlx, t_txtr *txtr, size_t size, int set)

{
	void	**frame;

	frame = (void **)malloc(sizeof(void *) * size);
	while (size--)
	{
		if (set == 0)
		{
			if (size == BACKGROUND_SIZE - 1)
				txtr->map->img->path[BACKGROUND_ID] = '0';
			else
				txtr->map->img->path[BACKGROUND_ID] = size + 'A';
			frame[size] = mlx_xpm_file_to_image(mlx->init, txtr->map->img->path,
					&txtr->map->img->width, &txtr->map->img->height);
		}
		else if (set == 2)
			frame[size] = mlx_opsprt(mlx->init, txtr->clct, CLCT_INDEX, size);
		else if (set == 3)
			frame[size] = mlx_opsprt(mlx->init, txtr->exit, EXIT_INDEX, size);
		else if (set == 4)
			frame[size] = mlx_opsprt(mlx->init, txtr->skin, SKIN_INDEX, size);
		if (!frame[size])
			ft_error("", "", mlx);
	}
	return (frame);
}
