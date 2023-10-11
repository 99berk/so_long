/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:21:30 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/11 17:50:20 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libraries/ft_printf/ft_printf.h"

static void	draw_wall(t_game *data, int x, int y)
{
	int	width;
	int	height;

	width = UNIT;
	height = UNIT;
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bg2.xpm", &width, &height);
	if (!data->wall_img)
	{
		ft_printf("Error: Could not load wall image.\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->wall_img, x * UNIT, y * UNIT);
}

static void	draw_floar(t_game *data, int x, int y)
{
	int	width;
	int	height;

	width = UNIT;
	height = UNIT;
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bg1.xpm", &width, &height);
	if (!data->floor_img)
	{
		ft_printf("Error: Could not load floor image.\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->floor_img, x * UNIT, y * UNIT);
}

static void	draw_exit(t_game *data, int x, int y)
{
	int	width;
	int	height;

	width = UNIT;
	height = UNIT;
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/door3.xpm", &width, &height);
	if (!data->exit_img)
	{
		ft_printf("Error: Could not load exit image.\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->exit_img, x * UNIT, y * UNIT);
}

static void	draw_collectible(t_game *data, int x, int y)
{
	int	width;
	int	height;

	width = UNIT;
	height = UNIT;
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/C1.xpm", &width, &height);
	if (!data->collectible_img)
	{
		ft_printf("Error: Could not load collectible image.\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->collectible_img, x * UNIT, y * UNIT);
}

void	draw_background(t_game *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_wall(data, x, y);
			if (data->map[y][x] == '0' || data->map[y][x] == 'P'
					|| data->map[y][x] == 'C' || data->map[y][x] == 'E')
				draw_floar(data, x, y);
			if (data->map[y][x] == 'E')
				draw_exit(data, x, y);
			if (data->map[y][x] == 'C')
				draw_collectible(data, x, y);
			x++;
		}
		y++;
	}
}
