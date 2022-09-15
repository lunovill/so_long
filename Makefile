# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunovill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 05:19:02 by lunovill          #+#    #+#              #
#    Updated: 2022/09/15 05:19:04 by lunovill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
SRC_FILES =	chk_all\
		chk_error\
		chk_path\
		chk_read\
		ft_create_map\
		ft_error\
		ft_init\
		ft_next_frame\
		ft_refresh_image\
		main\
		mlx_close\
		mlx_draw_image\
		mlx_event\
		mlx_malloc\
		mlx_open_xpm\
		mp_parsg\
		mp_tablen\
		so_long\

SRCS = $(addsuffix .c, $(SRC_FILES))

SRC_FILES_BONUS = $(addsuffix _bonus, $(SRC_FILES))
SRCS_BONUS = $(addsuffix .c, $(SRC_FILES_BONUS))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

LIBS_DIR = libft
MLX_DIR = minilibx

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes -I$(LIBS_DIR)/includes -Iminilibx
MLXLFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
CLFLAGS = -L$(LIBS_DIR) -lft

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = so_long
NAME_BONUS = so_long_bonus

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CLFLAGS) $(MLXLFLAGS) -o $(NAME)

$(OBJS_DIR) :
	$(MAKE) -C $(LIBS_DIR)
	$(MAKE) -C $(MLX_DIR)
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_DIR) $(OBJS_BONUS)
	$(MAKE) -C $(LIBS_DIR)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS_BONUS) $(CLFLAGS) $(MLXLFLAGS) -o $(NAME_BONUS)

$(OBJS_BONUS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME_BONUS).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

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
