/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:41:09 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/25 10:13:26 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <stdlib.h>

int	exitt(t_game *data)
{
	(void)data;
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
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
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
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	draw_background(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player_img,
		data->player_x, data->player_y);
	return (0);
}
