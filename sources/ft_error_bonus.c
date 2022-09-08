/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:05:54 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:05:55 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
