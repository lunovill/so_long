/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:41:29 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:41:35 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chk_size(const char **map, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (-1);
		i++;
	}
	return (0);
}

static void	chk_error(unsigned int tab[4])
{
	if (!tab[0])
		ft_error("map:\t", "missing collectible", NULL);
	if (!tab[1])
		ft_error("map:", "missing exit", NULL);
	if (!tab[2])
		ft_error("map:\t", "missing starting position", NULL);
	if (tab[1] > 1)
		ft_error("map:\t", "too many exit", NULL);
	if (tab[2] > 1)
		ft_error("map:\t", "too many starting position", NULL);
	if (tab[3] > 0)
		ft_error("map:\t", "invalid charater", NULL);
}

int	chk_map(const char **map, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tab[4];
	size_t			len;

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	len = ft_strlen(map[0]);
	if (chk_size(map, len) == -1)
		return (ft_error("map:\t", "no-rectangular map", NULL));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == size - 1) && map[i][j] != '1')
				return (-1);
			else if ((j == 0 || j == len -1) && map[i][j] != '1')
				return (-1);
			else if (map[i][j] == 'C')
				tab[0]++;
			else if (map[i][j] == 'E')
				tab[1]++;
			else if (map[i][j] == 'P')
				tab[2]++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				tab[3]++;
			j++;
		}
		i++;
	}
	if (!tab[0] || tab[1] != 1 || tab[2] != 1 || tab[3] != 0)
		return (chk_error(tab), -1);
	return (0);
}
