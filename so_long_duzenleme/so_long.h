/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:15:09 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/07 18:33:17 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx/mlx.h"
#include "./libraries/Libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

# define UNIT 64

typedef struct s_game
{
    void    *mlx_ptr;
    void    *mlx_win;
    int     player_x;
    int     player_y;
    void    *player_img;
    char    **map;
    void    *background_img;
    void    *wall_img;
    void    *collectible_img;
    void    *exit_img;
    int     collectibles_left;
    int     move_count;
}   t_game;

char    **read_map(char *file);
int     check_map_borders(char **map);
int     check_player_count(char **map);
int     check_exit_count(char **map);
int     check_map_characters(char **map);
int     check_map_rectangular(char **map);

#endif