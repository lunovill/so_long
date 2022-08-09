 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
SRC_FILES =	chk_map\
		ft_create_map\
		ft_error\
		ft_init\
		ft_next_frame\
		ft_post\
		ft_refresh_image\
		main\
		mlx_close\
		mlx_draw_image\
		mlx_event\
		mlx_win\
		mp_parsg\
		mp_tablen\
		mp_totab\

SRCS = $(addsuffix .c, $(SRC_FILES))

SRC_FILES_BONUS = $(addsuffix _bonus, $(SRC_FILES))
SRCS_BONUS = $(addsuffix .c, $(SRC_FILES_BONUS))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

 #=============================================================================#
#								  DEPENDANCE 									#
 #=============================================================================#

#  DEPS = $(OBJS:%.o=%.d)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

LIBS_DIR = libft
MLX_DIR = minilibx

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
# -MMD -MP
CIFLAGS = -Iincludes -I$(LIBS_DIR)/includes -Iminilibx
MLXLFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
CLFLAGS = -L$(LIBS_DIR) -lft

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = so_long
NAME_BONUS = so_long_bonus

# -include : $(DEPS)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(MAKE) -C $(LIBS_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CLFLAGS) $(MLXLFLAGS) -o $(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(CIFLAGS) -c $< -o $@

bonus : $(OBJS_DIR) $(BONUS)
	$(MAKE) -C $(LIBS_DIR)
	$(CC) $(CFLAGS) $(CIFLAGS) $(BONUS) $(CLFLAGS) $(MLXLFLAGS) -o $(NAME_BONUS)

$(BONUS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBS_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBS_DIR)
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
re : fclean all

.PHONY: clean fclean all re
