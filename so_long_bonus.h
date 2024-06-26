/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:15:09 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/25 17:45:22 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define UNIT 64

typedef struct s_enemy
{
	int		enemy_x;
	int		enemy_y;
	int		enemy_direction;
	void	*enemy_img;
}	t_enemy;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		player_x;
	int		player_y;
	void	*player_img[12];
	int		current_p_img;
	char	**map;
	void	*floor_img;
	void	*wall_img;
	void	*collectible_img[4];
	int		collectible_current_img;
	void	*exit_img;
	int		collectibles_left;
	int		move_count;
	t_enemy	*enemies;
	int		enemy_count;
}	t_game;

char	**read_map(char *file);
int		check_map_borders(char **map);
int		check_player_count(char **map);
int		check_exit_count(char **map);
int		check_map_characters(char **map);
int		check_map_rectangular(char **map);
int		check_file_extension(char *filename);
int		draw_background(t_game *data);
int		exitt(t_game *data);
int		key_handle(int key, t_game *data);
int		get_map_height(char **map);
int		get_map_width(char **map);
int		player(t_game *data);
void	draw_enemy(t_game *data, int x, int y, int index);
void	find_enemy_position(t_game *data);
void	draw_enemy_after_background(t_game *data);
void	img_uploud(t_game *data);

#endif
