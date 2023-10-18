/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:41:09 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/18 17:54:25 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include <stdlib.h>

void	destroy_img(t_game *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[2]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[3]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[4]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[5]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[6]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[7]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[8]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[9]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[10]);
	mlx_destroy_image(data->mlx_ptr, data->player_img[11]);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img[2]);
	mlx_destroy_image(data->mlx_ptr, data->collectible_img[3]);
}

int	exitt(t_game *data)
{
	int	i;
	
	free(data->enemies);
	destroy_img(data);
	mlx_destroy_image(data->mlx_ptr, data->floor_img);
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	system("leaks so_long");
	exit (1);
	return (0);
}

static int	count_collectibles(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	key_control(int key, t_game *data, int new_x, int new_y)
{
	if (key == 53)
		exitt(data);
	if (key == 13)
		data->player_y -= UNIT;
	if (key == 1)
		data->player_y += UNIT;
	if (key == 0)
		data->player_x -= UNIT;
	if (key == 2)
		data->player_x += UNIT;
	if (data->map[data->player_y / UNIT][data->player_x / UNIT] == '1')
	{
		data->player_x = new_x;
		data->player_y = new_y;
	}
	else if (key == 13 || key == 1 || key == 2 || key == 0)
		data->move_count++;
}

int	key_handle(int key, t_game *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	key_control(key, data, new_x, new_y);
	if (data->map[data->player_y / UNIT][data->player_x / UNIT] == 'C')
		data->map[data->player_y / UNIT][data->player_x / UNIT] = '0';
	data->collectibles_left = count_collectibles(data->map);
	if (data->map[data->player_y / UNIT][data->player_x / UNIT] == 'E'
			&& data->collectibles_left == 0)
		exitt(data);
	return (0);
}
