/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:36:15 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 22:36:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chk_arg(const char *arg)
{
	unsigned int	len;

	if (!arg)
		return (-1);
	len = ft_strlen(arg);
	if (len < 5)
		return (-1);
	len -= 4;
	if (ft_strcmp(arg + len, ".ber") != 0)
		return (-1);
	return (0);
}

static size_t	mp_totabsiz(char **map)
{
	size_t	size;

	size = 0;
	while (map[size])
		size ++;
	return (size);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	size_t	size;

	if (argc != 2)
	{
		if (argc == 1)
			return (ft_error("missing operand", NULL));
		return (ft_error("too mamy arguments", NULL));
	}
	if (chk_arg(argv[1]) == -1)
		return (ft_error("use:\t./so_long [map].ber", NULL));
	fd = open(argv[1], __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), ft_putstr_fd("so_long: ", 2), ft_putstr_fd(argv[1], 2), ft_putstr_fd(" is a directory\n", 2), -1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	map = mp_totab(fd);
	size = mp_totabsiz(map);
	close(fd);
	if (chk_map(map, size) == -1)
		return (ft_ftab(map), ft_error("invalid map", NULL));
	mlx_win(mp_parsg(map));
	return (0);
}
