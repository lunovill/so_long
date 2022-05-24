#include "so_long.h"

static int	chk_size(char **map, size_t len)
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

static void	chk_error(unsigned int tab[3])
{
	ft_putstr_fd("Error\n", 2);
	if (!tab[0])
		ft_putstr_fd("so_long: missing collectible\n", 2);
	if (!tab[1])
		ft_putstr_fd("so_long: missing exit\n", 2);
	if (!tab[2])
		ft_putstr_fd("so_long: missing starting position\n", 2);
	if (tab[1] > 1)
		ft_putstr_fd("so_long: too many exit\n", 2);
	if (tab[2] > 1)
		ft_putstr_fd("so_long: too many starting position\n", 2);
}

int	chk_map(char **map, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tab[3];
	size_t		len;

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	len = ft_strlen(map[0]);
	if (chk_size(map, len) == -1)
		return (ft_error("non-rectangular map\n"), -1);
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
			j++;
		}
		i++;
	}
	if (!tab[0] || tab[1] !=  1 || tab[2] != 1)
		return (chk_error(tab), -1);
	return (0);
}