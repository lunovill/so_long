/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_parsg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:06:58 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:14:37 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mp_ceptonum(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (map->coor[++i])
	{
		j = -1;
		while (map->coor[i][++j])
		{
			if (map->coor[i][j] == 'C')
				map->coor[i][j] = '2';
			if (map->coor[i][j] == 'E')
				map->coor[i][j] = '3';
			if (map->coor[i][j] == 'P')
				map->coor[i][j] = '4';
		}
	}
	return ;
}

static void	mp_lenght(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (map->coor[++i])
		;
	map->height = i;
	i = -1;
	while (map->coor[0][++i])
		;
	map->width = i;
}

static void	mp_border(t_map *map)
{
	unsigned int	i;

	map->coor[0][0] = 'Q';
	map->coor[0][map->width - 1] = 'S';
	map->coor[map->height - 1][0] = 'W';
	map->coor[map->height - 1][map->width - 1] = 'U';
	i = 0;
	while (++i < map->width - 1)
		map->coor[0][i] = 'R';
	i = 0;
	while (++i < map->width - 1)
		map->coor[map->height - 1][i] = 'V';
	i = 0;
	while (++i < map->height - 1)
		map->coor[i][0] = 'X';
	i = 0;
	while (++i < map->height - 1)
		map->coor[i][map->width - 1] = 'T';
	return ;
}

static char	mp_wall(t_map *map, unsigned int x, unsigned int y)
{
	int	wall;

	wall = 0;
	if ('A' <= map->coor[y - 1][x] && map->coor[y - 1][x] <= 'P')
		wall += 1;
	if (map->coor[y][x + 1] == '1')
		wall += 2;
	if (map->coor[y + 1][x] == '1')
		wall += 4;
	if ('A' <= map->coor[y][x - 1] && map->coor[y][x - 1] <= 'P')
		wall += 8;
	return (wall + 65);
}

t_map	*mp_parsg(char **coor)
{
	unsigned int	x;
	unsigned int	y;
	t_map			*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_ftab(coor), NULL);
	map->coor = coor;
	mp_ceptonum(map);
	mp_lenght(map);
	mp_border(map);
	y = 0;
	while (map->coor[++y + 1])
	{
		x = 0;
		while (map->coor[y][++x + 1])
			if (map->coor[y][x] == '1')
				map->coor[y][x] = mp_wall(map, x, y);
	}
	map->img = NULL;
	return (map);
}
