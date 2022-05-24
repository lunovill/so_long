#include "so_long.h"

char 	**ft_get_map(int fd, char	*str)
{
	char	**map;
	char	*tmp;
	int	ret;

	ret = 42;
	while (ret)
	{
		ret = get_next_line(fd, &tmp);
		if (ret == -1)
		{
			if (str)
				free(str);
			return (NULL);
		}
		tmp = ft_strjoinf(tmp, "\n", 1);
		str = ft_strjoinf(tmp, str, 0);
	}
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		return (NULL);
	return (map);
}

char	**ft_map(int fd)
{
	char	**map;
	char	*str;
	int		ret;

	ret = get_next_line(fd, &str);
	if (ret == -1)
	{
		map = ft_split(str, '\n');
		free(str);
	}
	else
	{
		str = ft_strjoinf(str, "\n", 1);
		map = ft_get_map(fd, str);
	}
	return (map);
}