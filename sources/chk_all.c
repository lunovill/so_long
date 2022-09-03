/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:56:17 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/03 22:56:25 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*error_init(void)
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

static int	*chk_char(char c, int error[6])
{
	if (c == 'C')
		error[2]++;
	else if (c == 'E')
		error[3]++;
	else if (c == 'P')
		error[4]++;
	else if (c != '0' && c != '1')
		error[5]++;
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
			error = chk_char(s[i], error);
		if (s[i] != '1')
			error[0]++;
	}
	return (error);
}

static int	*chk_read(int fd, char **str, int ret, int error[6])
{
	char			*tmp;
	unsigned int	size;

	error = chk_line(*str, error, 1);
	size = ft_strlen(*str);
	*str = ft_strjoinf(*str, "\n", 1);
	while (ret)
	{
		ret = get_next_line(fd, &tmp, 1);
		if (ret == -1)
			return (ft_free(*str), NULL);
		if (size != ft_strlen(tmp))
			error[1]++;
		if (ret)
			error = chk_line(tmp, error, 0);
		else
			error = chk_line(tmp, error, 1);
		tmp = ft_strjoinf(tmp, "\n", 1);
		if (!tmp)
			return (ft_free(*str), NULL);
		*str = ft_strjoinf(*str, tmp, 0);
		if (!*str)
			return (NULL);
	}
	return (error);
}

char	**chk_all(int fd)
{
	char			**map;
	char			*str;
	int				*error;
	int				erno;
	int				ret;

	error = error_init();
	if (!error)
		return (NULL);
	ret = get_next_line(fd, &str, 1);
	if (ret == -1)
		return (NULL);
	error = chk_read(fd, &str, ret, error);
	if (!error)
		return (NULL);
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
