#ifndef SO_LONG_H
# define SO_LONG_H
# define GAME_NAME "so_long"
# define W_CASE 80
# define H_CASE 80
# define BACKGROUND "./textures/background/_.xpm"
# define BACKGROUND_ID 22
# define BACKGROUND_SIZE 25
# define SKIN "./textures/sprites/skin/__.xpm"
# define SKIN_ID 24
# define SKIN_SIZE 32
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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sline;
	int		endian;
	char	*post;
}				t_data;

typedef	struct s_imgs
{
	t_data			data;
	int				width;
	int				height;
	char			*path;
	void			**xpm;
}				t_imgs;

typedef struct s_map
{
	t_imgs	img;
	char	**coor;
	size_t	width;
	size_t	height;
}				t_map;

typedef struct	s_txtr
{
	t_data	data;
	t_map	map;
	t_imgs	skin;
	// t_sprt	clct;
	// t_sprt	exit;
}				t_txtr;

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	t_txtr	txtr;
}				t_mlx;

void    ft_post(char **post, int n);
void    ft_init(t_mlx *mlx, t_map *map);
void	mlx_draw_image(t_data img, t_data txtr, unsigned int row, unsigned int col);
void	mlx_close(t_mlx *mlx, int code_exit);
int		ft_error(const char *error, t_mlx *mlx);
int		chk_map(char **map, size_t size);
int     mlx_win(t_map map);
char	**mp_totab(int fd);
t_map	mp_parsg(char **coor);
int		ft_creat_image(t_mlx *mlx);

#endif
