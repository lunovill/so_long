/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_all_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:03:34 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 18:03:37 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	**chk_all(int fd)
{
	char			**map;
	char			*str;
	int				*error;
	int				erno;

	error = error_init();
	if (!error)
		return (NULL);
	error = chk_read(fd, &str, error);
	close(fd);
	if (!error)
		return (get_next_line(fd, &str, 0), ft_free(str), NULL);
	erno = chk_error(error);
	if (erno)
		return (ft_free(str), exit(erno), NULL);
	map = ft_split(str, '\n');
	ft_free(str);
	if (!map)
		return (NULL);
	return (map);
}
