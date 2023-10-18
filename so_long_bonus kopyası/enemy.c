/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:45 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/18 18:02:27 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <stdlib.h>

void	find_enemy_position_part2(t_game *data)
{
	int	y;
	int	x;
	int	enemy_index;

	y = 0;
	x = 0;
	enemy_index = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'F')
			{
				data->enemies[enemy_index].enemy_x = x * UNIT;
				data->enemies[enemy_index].enemy_y = y * UNIT;
				data->enemies[enemy_index].enemy_direction = 1;
				enemy_index++;
			}
			x++;
		}
		y++;
	}
}

void	find_enemy_position(t_game *data)
{
	int	y;
	int	x;
	int	enemy_index;

	y = 0;
	x = 0;
	enemy_index = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'F')
				enemy_index++;
			x++;
		}
		y++;
	}
	data->enemy_count = enemy_index;
	data->enemies = (t_enemy *)malloc(sizeof(t_enemy) * data->enemy_count);
	if (!data->enemies)
		exitt(data);
	find_enemy_position_part2(data);
}

int	move_enemy(t_game *data, int enemy_index)
{
	int	new_x;
	int	new_y;

	new_x = data->enemies[enemy_index].enemy_x;
	new_y = data->enemies[enemy_index].enemy_y;
	if (data->enemies[enemy_index].enemy_direction == 1)
		new_y += 18;
	else
		new_y -= 18;
	if (data->map[new_y / UNIT][new_x / UNIT] == '1')
	{
		data->enemies[enemy_index].enemy_direction *= -1;
		new_y += UNIT * data->enemies[enemy_index].enemy_direction;
	}
	data->enemies[enemy_index].enemy_y = new_y;
	return (new_y);
}

void	draw_enemy(t_game *data, int x, int y, int enemy_index)
{
	int	img_size;

	img_size = UNIT;
	y = move_enemy(data, enemy_index) / UNIT;
	data->enemies[enemy_index].enemy_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/enemy_img.xpm", &img_size, &img_size);
	if (!data->enemies[enemy_index].enemy_img)
	{
		ft_printf("Error\nCould not load enemy image.\n");
		exitt(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->enemies[enemy_index].enemy_img, x * UNIT, y * UNIT);
	if (data->player_y == (y * UNIT) && data->player_x == (x * UNIT))
		exitt(data);
}

void	draw_enemy_after_background(t_game *data)
{
	int	enemy_index;

	enemy_index = 0;
	while (enemy_index < data->enemy_count)
	{
		draw_enemy(data, data->enemies[enemy_index].enemy_x / UNIT,
			data->enemies[enemy_index].enemy_y / UNIT, enemy_index);
		enemy_index++;
	}
}
