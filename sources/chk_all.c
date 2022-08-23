#include "so_long.h"

static int *error_init(void)
{
	int	*error;

	error = (int *)malloc(sizeof(int) * 6);
	if (!error)
		return (NULL);
	error[0] = 0;
	error[1] = 0;
	error[2] = 0;
	error[3] = 1;
	error[4] = 1;
	error[5] = 0;
	return (error);
}

static int	*chk_line(const char *s, int error[6], int set)
{
	unsigned int	i;

	i = 0;
	if (set)
	{
	while (s[i])
		if (s[i++] != '1')
			error[0]++;
	}
	else
	{
		if (s[i] != '1')
			error[0]++;
		while (s[++i + 1])
		{
			if (s[i] == 'C')
				error[2]++;
			else if (s[i] == 'E')
				error[3]++;
			else if (s[i] == 'P')
				error[4]++;
			else if (s[i] != '0' && s[i] != '1')
				error[5]++;
		}
		if (s[i] != '1')
			error[0]++;
	}
	return (error);
}

static int	chk_error(int error[6])
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
	if (error[0] || error[1] || !error[2] || error[3] != 2 || error[4] != 2 || error[5])
		return (ft_free(error), erno);
	return (ft_free (error), 0);
}

char	**chk_all(int fd)
{
	char	**map;
	char	*str;
	char	*tmp;
	int		ret;
	unsigned int size;
	int		*error;
	int		erno;

	error = error_init();
	if (!error)
		return (NULL);
    ret = get_next_line(fd, &str, 1);
    if (ret == -1)
		return (NULL);
	error = chk_line(str, error, 1);
	size = ft_strlen(str);
	str = ft_strjoinf(str, "\n", 1);
	if (!str)
		return (NULL);
	while (ret)
	{
		ret = get_next_line(fd, &tmp, 1);
		if (ret == -1)
			return (ft_free(str), NULL);
		if (size != ft_strlen(tmp))
			error[1]++;
		if (ret)
			error = chk_line(tmp, error, 0);
		else
			error = chk_line(tmp, error, 1);
		tmp = ft_strjoinf(tmp, "\n", 1);
		if (!tmp)
			return (ft_free(str), NULL);
		str = ft_strjoinf(str, tmp, 0);
		if (!str)
			return (NULL);
	}
	close(fd);
	erno = chk_error(error);
	if (erno)
		return (ft_free(str), exit(erno), NULL);
	map = ft_split(str, '\n');
	ft_free(str);
	if (!map)
		return (NULL);
	return (map);
}