/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:45 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/14 18:42:39 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <stdlib.h>

void	find_enemy_position(t_game *data)
{
	int	y = 0;
	int	x = 0;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'F')
			{
				data->enemy_x = x * UNIT;
				data->enemy_y = y * UNIT;
			}
			x++;
		}
		y++;
	}
}

int move_enemy(t_game *data)
{
    int new_x = data->enemy_x;
    int new_y = data->enemy_y;
	static int i = 1;
	if (i == 1)
		new_y += 18;
	else
		new_y -= 18;
    if (data->map[new_y / UNIT][new_x / UNIT] == '1')
	{
        i = i*(-1);
		new_y = new_y + (18 * i);
		return (new_y);
	}
	data->enemy_y = new_y; 
	return (new_y);
}

void	draw_enemy(t_game *data, int x, int y)
{
	int img_size;
	
	img_size = UNIT;
	y = move_enemy(data) / UNIT;
    data->enemy_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/enemy_img.xpm", &img_size, &img_size);
    if (!data->enemy_img)
    {
        ft_printf("Error\nCould not load enemy image.\n");
        exit(1);
    }
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->enemy_img, x * UNIT, y * UNIT);
	if (data->player_y == (y * UNIT) && data->player_x == (x * UNIT))
		exit(1);
}