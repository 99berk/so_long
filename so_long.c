/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:18:26 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/25 11:37:07 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <stdlib.h>

void	find_player_position(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x * UNIT;
				data->player_y = y * UNIT;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	player(t_game *data)
{
	int	img_width;
	int	img_height;

	img_width = UNIT;
	img_height = UNIT;
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img.xpm", &img_width, &img_height);
	if (!data->player_img)
	{
		ft_printf("Error\nLoading player image.\n");
		exit(1);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player_img,
		data->player_x, data->player_y);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;
	int		map_width;
	int		map_height;

	if (ac == 2)
	{
		check_file_extension(av[1]);
		data.map = read_map(av[1]);
		if (!data.map || !check_map_characters(data.map)
			|| !check_map_rectangular(data.map) || !check_map_borders(data.map)
			|| !check_player_count(data.map) || !check_exit_count(data.map))
			exit(1);
		map_width = get_map_width(data.map);
		map_height = get_map_height(data.map);
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, UNIT * map_width,
				UNIT * map_height, "So_long");
		draw_background(&data);
		find_player_position(&data);
		player(&data);
		mlx_hook(data.mlx_win, 17, 0, exitt, &data);
		mlx_hook(data.mlx_win, 2, 0, key_handle, &data);
		mlx_loop(&data);
	}
	return (ft_printf("Error\nWrong arguman number.\n"), 0);
}
