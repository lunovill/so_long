/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:47:57 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:47:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(const char *arg, const char *error, t_mlx *mlx)
{
	ft_putstr_fd("so_long:\t", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	if (mlx)
		mlx_close(mlx, EXIT_FAILURE);
	return (-1);
}
