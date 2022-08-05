/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_totab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:10:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/07/22 23:10:48 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_get_map(int fd, char *str)
{
	char	**map;
	char	*tmp;
	int		ret;

	ret = 42;
	while (ret)
	{
		ret = get_next_line(fd, &tmp, 1);
		if (ret == -1)
			return (ft_free(str), NULL);
		tmp = ft_strjoinf(tmp, "\n", 1);
		if (!tmp)
			return (ft_free(str), NULL);
		str = ft_strjoinf(str, tmp, 0);
		if (!str)
			return (NULL);
	}
	map = ft_split(str, '\n');
	ft_free(str);
	if (!map)
		return (NULL);
	return (map);
}

char	**mp_totab(int fd)
{
	char	**map;
	char	*str;

	get_next_line(fd, &str, 1);
	str = ft_strjoinf(str, "\n", 1);
	if (!str)
		return (NULL);
	map = ft_get_map(fd, str);
	return (map);
}
