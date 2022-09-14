/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:56:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/09/08 19:05:08 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define GAME_NAME "so_long_bonus"
# define W_CASE 80
# define H_CASE 80
# define BACKGROUND "./textures/background/_.xpm"
# define BACKGROUND_ID 22
# define BACKGROUND_SIZE 25
# define SKIN_PATH "./textures/sprites/skin/__.xpm"
# define SKIN_INDEX 24
# define CLCT_PATH "./textures/collectibles/__.xpm"
# define CLCT_INDEX 24
# define EXIT_PATH "./textures/exit/__.xpm"
# define EXIT_INDEX 16
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

typedef enum e_keycode
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	KEY_ESC = 65307,
}				t_keycode;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sline;
	int		endian;
}				t_data;

typedef struct s_imgs
{
	t_data			*data;
	char			*path;
	void			*frame;
	int				width;
	int				height;
	unsigned int	index;
	unsigned int	x;
	unsigned int	y;
}				t_imgs;

typedef struct s_map
{
	t_imgs	*img;
	char	**coor;
	void	**frame;
	size_t	width;
	size_t	height;
}				t_map;

typedef struct s_txtr
{
	t_data	*data;
	t_map	*map;
	t_imgs	*skin;
	t_imgs	*clct;
	t_imgs	*exit;
}				t_txtr;

typedef struct s_key
{
	int	up;
	int	left;
	int	down;
	int	right;
}				t_key;

typedef struct s_mlx
{
	void			*init;
	void			*win;
	t_txtr			*txtr;
	int				wrslt;
	int				hrslt;
	t_key			*key;
	unsigned int	count;
}				t_mlx;

int		*chk_read(int fd, char **str, int error[6]);
int		chk_error(int error[6]);
int		chk_path(char **map);
char	**chk_all(int fd);

size_t	mp_tablen(const char **map);
t_map	*mp_parsg(char **coor);

int		ft_error(const char *arg, const char *error, t_mlx *mlx);
int		ft_init(t_mlx *mlx, t_map *map);
int		ft_create_map(t_data *data, t_map *map, t_txtr *txtr);
int		ft_refresh_image(t_mlx *mlx);
void	ft_next_frame(t_mlx *mlx, char c);

int		mlx_malloc(t_mlx *mlx, t_map *map);
int		mlx_opsprt(void *init, t_imgs *sprt, unsigned int id, size_t size);
int		mlx_opmap(void *init, t_map *map, size_t size);
int		mlx_draw_image(t_data *img, t_data *txtr,
			unsigned int row, unsigned int col);
int		mlx_key_press(int keycode, t_mlx *mlx);
int		mlx_close(t_mlx *mlx, int code_exit);
int		so_long(t_map *map);

#endif
