/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_parsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:06:58 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 23:07:39 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// static char	mp_wall(t_map *map, unsigned int x, unsigned int y)
// {
// 	int	power[4];

// 	if ('0' <= map->coor[y - 1][x] && map->coor[y - 1][x] <= '4')
// 		power[0] = 0;
// 	else
// 		power[0] = 1;
// 	if (('0' <= map->coor[y][x + 1] && map->coor[y][x + 1] <= '4') && map->coor[y][x + 1] != '1')
// 		power[1] = 0;
// 	else
// 		power[1] = 2;
// 	if ((('0' <= map->coor[y + 1][x] && map->coor[y + 1][x] <= '4') && map->coor[y + 1][x] != '1') || map->coor[y + 1][x] == 'Z')
// 		power[2] = 0;
// 	else
// 		power[2] = 4;
// 	if ('0' <= map->coor[y][x - 1] && map->coor[y][x - 1] <= '4')
// 		power[3] = 0;
// 	else
// 		power[3] = 8;
// 	return (power[0] + power[1] + power[2] + power[3] + 65);
// }

static char	mp_wall(t_map *map, unsigned int x, unsigned int y)
{
	int	power[4];

	if ('A' <= map->coor[y - 1][x] && map->coor[y - 1][x] <= 'P')
		power[0] = 1;
	else
		power[0] = 0;
	if (map->coor[y][x + 1] == '1')
		power[1] = 2;
	else
		power[1] = 0;
	if (map->coor[y + 1][x] == '1')
		power[2] = 4;
	else
		power[2] = 0;
	if ('A' <= map->coor[y][x - 1] && map->coor[y][x - 1] <= 'P')
		power[3] = 8;
	else
		power[3] = 0;
	return (power[0] + power[1] + power[2] + power[3] + 65);
}

t_map	mp_parsg(char **coor)
{
	unsigned int	x;
	unsigned int	y;
	t_map			map;

	map.coor = coor;
	mp_ceptonum(&map);
	mp_lenght(&map);
	mp_border(&map);
	y = 0;
	while (map.coor[++y + 1])
	{
		x = 0;
		while (map.coor[y][++x + 1])
			if (map.coor[y][x] == '1')
				map.coor[y][x] = mp_wall(&map, x, y);
	}
	// unsigned int i = -1;
	// while (map.coor[++i])
	// ft_printf("%s\n", map.coor[i]);
	return (map);
}
