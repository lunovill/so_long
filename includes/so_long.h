#ifndef SO_LONG_H
# define SO_LONG_H
# define GAME_NAME "so_long"
# define W_CASE 80
# define H_CASE 80
# define BACKGROUND "./textures/background/_.xpm"
# define BACKGROUND_ID 22
# define BACKGROUND_SIZE 25
# define SKIN_PATH "./textures/sprites/skin/__.xpm"
# define SKIN_INDEX 24
# define SKIN_SIZE 32
# define CLCT_PATH "./textures/collectibles/__.xpm"
# define CLCT_INDEX 24
# define CLCT_SIZE 8
# define EXIT_PATH "./textures/exit/__.xpm"
# define EXIT_INDEX 16
# define EXIT_SIZE 8
# define SPEED 3
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
	KEY_ARROW_UP = 65362,
	KEY_ARROW_RIGHT = 65363,
	KEY_ARROW_DOWN = 65364,
	KEY_ARROW_LEFT = 65361,
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

typedef	struct s_imgs
{
	t_data			*data;
	int				width;
	int				height;
	char			*path;
	void			**frame;
	unsigned int	index;
	unsigned int	x;
	unsigned int	y;
}				t_imgs;

typedef struct s_map
{
	t_imgs	*img;
	char	**coor;
	size_t	width;
	size_t	height;
}				t_map;

typedef struct	s_txtr
{
	t_data	*data;
	t_map	*map;
	t_imgs	*skin;
	t_imgs	*clct;
	t_imgs	*exit;
}				t_txtr;

typedef struct	s_key
{
	int up;
	int left;
	int down;
	int right;
}				t_key;

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	t_txtr	*txtr;
	t_key	*key;
	int		speed;
}				t_mlx;

int		chk_map(const char **map, size_t size);
char	**chk_all(int fd);

size_t	mp_tablen(const char **map);
char	**mp_totab(int fd);
t_map	*mp_parsg(char **coor);

int    ft_init(t_mlx *mlx, t_map *map);
void	ft_create_map(t_data *data, t_map *map);
int		ft_refresh_image(t_mlx *mlx);
void	ft_next_frame(t_mlx *mlx);
int		ft_error(const char *arg, const char *error, t_mlx *mlx);

int     mlx_win(t_map *map);
void	mlx_draw_image(t_data *img, t_data *txtr, unsigned int row, unsigned int col);
int		mlx_key_press(int keycode, t_mlx *mlx);
int		mlx_key_release(int keycode, t_mlx *mlx);
int		mlx_close(t_mlx *mlx, int code_exit);

#endif
