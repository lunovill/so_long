/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:55:41 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/14 21:56:59 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		while (s[1] && s[++i + 1])
			error = chk_char(s[i], error);
		if (s[i] != '1')
			error[0]++;
	}
	return (error);
}

int	*chk_read2(int fd, char **str, int ret, int error[6])
{
	char			*tmp;
	unsigned int	size;

	size = ft_strlen(*str) - 1;
	while (ret)
	{
		ret = get_next_line(fd, &tmp, 1);
		if (ret == -1)
			return (ft_free(error), get_next_line(fd, &tmp, 0), NULL);
		if (size != ft_strlen(tmp))
			error[1]++;
		if (ret)
			error = chk_line(tmp, error, 0);
		else
			error = chk_line(tmp, error, 1);
		tmp = ft_strjoinf(tmp, "\n", 1);
		if (!tmp)
			return (ft_free(error), get_next_line(fd, &tmp, 0),
				ft_free(tmp), NULL);
		*str = ft_strjoinf(*str, tmp, 0);
		if (!*str)
			return (ft_free(error), get_next_line(fd, &tmp, 0),
				ft_free(tmp), NULL);
	}
	return (error);
}

int	*chk_read(int fd, char **str, int error[6])
{
	int				ret;

	ret = get_next_line(fd, &*str, 1);
	if (ret == -1)
		return (ft_free(error), NULL);
	error = chk_line(*str, error, 1);
	*str = ft_strjoinf(*str, "\n", 1);
	if (!*str)
		return (ft_free(error), NULL);
	return (chk_read2(fd, &*str, ret, error));
}
