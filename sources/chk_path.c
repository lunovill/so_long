/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:01:14 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/09 01:01:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_search_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	else if (map[y][x] == '1')
		return (0);
	map[y][x] = '*';
	if (map[y - 1][x] != '*' && ft_search_exit(map, x, y - 1) == 1)
		return (1);
	else if (map[y][x + 1] != '*' && ft_search_exit(map, x + 1, y) == 1)
		return (1);
	else if (map[y + 1][x] != '*' && ft_search_exit(map, x, y + 1) == 1)
		return (1);
	else if (map[y][x - 1] != '*' && ft_search_exit(map, x - 1, y) == 1)
		return (1);
	return (0);
}

int	chk_path(char **map)
{
	int	x;
	int	y;
	int	ret;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P')
				break ;
		if (map[y][x] == 'P')
			break ;
	}
	ret = ft_search_exit(map, x, y);
	ft_ftab(map);
	return (ret);
}
