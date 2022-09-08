/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:04:29 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:04:32 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	chk_error(int error[6])
{
	int	erno;

	erno = error[0] + error[1] + error[3] + error[4] + error[5];
	if (error[0])
		ft_error("map:\t", "map not closed by walls '1'", NULL);
	if (error[1])
		ft_error("map:\t", "no-rectangular map", NULL);
	if (!error[2])
		ft_error("map:\t", "missing collectible(s) 'C'", NULL);
	if (error[3] == 1)
		ft_error("map:\t", "missing exit 'E'", NULL);
	if (error[4] == 1)
		ft_error("map:\t", "missing starting position 'P'", NULL);
	if (2 < error[3])
		ft_error("map:\t", "too many exit 'E'", NULL);
	if (2 < error[4])
		ft_error("map:\t", "too many starting position 'P'", NULL);
	if (error[5])
		ft_error("map:\t", "invalid character(s)", NULL);
	if (error[0] || error[1] || !error[2]
		|| error[3] != 2 || error[4] != 2 || error[5])
		return (ft_free(error), erno);
	return (ft_free (error), 0);
}
