# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 14:14:29 by bakgun            #+#    #+#              #
#    Updated: 2023/10/25 17:51:29 by bakgun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := so_long.c read_map.c check_control.c draw_img.c key_handle.c
SOURCE_B := so_long_bonus.c read_map_bonus.c check_control_bonus.c draw_img_bonus.c key_handle_bonus.c img_upload_bonus.c enemy_bonus.c
GETNEXTLINE := libraries/get_next_line/*c
LIBFT := libraries/libft/ft_*.c
FTPRINTF := libraries/ft_printf/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(FTPRINTF) $(LIBFT) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

bonus:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE_B) $(FTPRINTF) $(LIBFT) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	@rm -f  *.o

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re