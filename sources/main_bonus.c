/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:10:02 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:10:04 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	chk_arg(const char *arg)
{
	unsigned int	len;

	if (!arg || arg[0] == '.')
		return (-1);
	len = ft_strlen(arg);
	if (len < 5)
		return (-1);
	len -= 4;
	if (ft_strcmp(arg + len, ".ber") != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2)
	{
		if (argc == 1)
			return (ft_error("", "missing operand", NULL));
		return (ft_error("", "too mamy arguments", NULL));
	}
	if (chk_arg(argv[1]) == -1)
		return (ft_error("use:\t", "./so_long [map].ber", NULL));
	fd = open(argv[1], __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), ft_error(argv[1], " is a directory\n", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("", "", NULL), perror("open"), -1);
	map = chk_all(fd);
	if (!map)
		return (ft_error("map:\t", "error", NULL), -1);
	if (!chk_path(ft_tabdup((const char **)map)))
		return (ft_ftab(map), ft_error("map:\t", "no valid path", NULL), -1);
	return (so_long(mp_parsg(map)));
}
