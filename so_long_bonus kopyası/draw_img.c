/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:21:30 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/18 18:07:04 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include <stdlib.h>
static void	draw_wall(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->wall_img, x * UNIT, y * UNIT);
}

static void	draw_floar(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->floor_img, x * UNIT, y * UNIT);
}

static void	draw_exit(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->exit_img, x * UNIT, y * UNIT);
}

static void	draw_collectible(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->collectible_img[data->collectible_current_img],
		x * UNIT, y * UNIT);
	data->collectible_current_img = (data->collectible_current_img + 1) % 4;
}

int	draw_background(t_game *data)
{
	int	y;
	int	x;

	x = -1;
	y = 0;
	while (data->map[y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
				draw_wall(data, x, y);
			if (data->map[y][x] == '0'
				|| data->map[y][x] == 'P' || data->map[y][x] == 'C'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'F')
				draw_floar(data, x, y);
			if (data->map[y][x] == 'E')
				draw_exit(data, x, y);
			if (data->map[y][x] == 'C')
				draw_collectible(data, x, y);
		}
		y++;
	}
	draw_enemy_after_background(data);
	return (0);
}
