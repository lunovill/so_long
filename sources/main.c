#include "so_long.h"

int	chk_arg(const char *arg)
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
	int	fd;
	char	**map;
	size_t	size;

	if (argc != 2)
	{
		if (argc == 1)
			return (ft_error("missing operand\n"));
		return (ft_error("too mamy arguments\n"));
	}
	if (chk_arg(argv[1]) == -1)
		return (ft_error("use:\t./so_long [map].ber\n"));
	fd = open(argv[1], __O_DIRECTORY);
	if (fd != -1)
		return(close(fd), ft_error(argv[1]), ft_putstr_fd(" is a directory\n", 2), -1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open"), -1);
	map = mp_totab(fd);
	size = mp_totabsiz(map);
	close(fd);
	if (chk_map(map, size) == -1)
		return (ft_ftab(map), ft_putstr_fd("so_long: invalid map\n", 2));
	mlx_win(mp_parsg(map));
	return (0);
}
