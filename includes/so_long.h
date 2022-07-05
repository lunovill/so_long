#ifndef SO_LONG_H
# define SO_LONG_H
# define GAME_NAME "so_long"
# define W_CASE 80
# define H_CASE 80
# define BACKGROUND "./textures/background/_.xpm"
# define BACKGROUND_ID 22
# define SKIN "./textures/sprites/skin/_.xpm"
# define SKIN_ID 24
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

typedef enum e_keycode {
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	KEY_ESC = 65307,
}				t_keycode;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sline;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**coor;
	size_t	width;
	size_t	height;
}				t_map;

typedef	struct s_sprt
{
	t_data	data;
	int	width;
	int	height;
}				t_sprt;

typedef struct	s_txtr
{
	t_data	data;
	t_map	map;
	t_sprt	skin;
	// t_sprt	clct;
	// t_sprt	exit;
}				t_txtr;

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	t_txtr	txtr;
}				t_mlx;

void	mlx_draw_image(t_data img, t_data txtr, unsigned int row, unsigned int col);
int		chk_map(char **map, size_t size);
int		ft_error(const char *error);
int     mlx_win(t_map map);
char	**mp_totab(int fd);
t_map	mp_parsg(char **coor);
t_txtr	ft_creat_image(t_mlx	mlx, t_map map);

#endif
