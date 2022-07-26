/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:06:36 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 23:06:37 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_win(t_map map)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	if (!mlx.init)
		return (ft_ftab(map.coor), ft_error("mlx:\t", "mlx doesn't initialize", NULL));
	ft_init(&mlx, &map);
	mlx.win = mlx_new_window(mlx.init, map.width * W_CASE, map.height * H_CASE, GAME_NAME);
	if (!mlx.win)
		return (ft_error("mlx:\t", "window doesn't open", &mlx));
	mlx.txtr.data.img = mlx_new_image(mlx.init, mlx.txtr.map.width * W_CASE, mlx.txtr.map.height * H_CASE);
	if (!mlx.txtr.data.img)
		return (ft_error("mlx:\t", "map doesn't creat", &mlx));
	mlx.txtr.data.addr = mlx_get_data_addr(mlx.txtr.data.img, &mlx.txtr.data.bpp, &mlx.txtr.data.sline, &mlx.txtr.data.endian);
	if (!mlx.txtr.data.addr)
		return (ft_error("mlx:\t", "image bad addr", &mlx));
	ft_creat_map(mlx.txtr.data, mlx.txtr.map);
	if (mlx_loop_hook(mlx.init, ft_refresh_image, &mlx) == -1)
		return (ft_error("mlx:\t", "bad image", &mlx));
	mlx_hook(mlx.win, 02, 1L << 0, mlx_event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
