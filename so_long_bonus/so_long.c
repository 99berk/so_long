/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:18:26 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/14 17:58:31 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./minilibx/mlx.h"
#include "./libraries/Libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

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

void	get_player_img(t_game *data)
{
	int	img_size;

	img_size = UNIT;
	data->player_img[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img5.xpm", &img_size, &img_size);
	data->player_img[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img6.xpm", &img_size, &img_size);
	data->player_img[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img7.xpm", &img_size, &img_size);
	data->player_img[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img8.xpm", &img_size, &img_size);
	data->player_img[9] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img9.xpm", &img_size, &img_size);
	data->player_img[10] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img10.xpm", &img_size, &img_size);
	data->player_img[11] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img11.xpm", &img_size, &img_size);
	if (!data->player_img[data->current_p_img])
	{
		ft_printf("Error\nLoading player image.\n");
		exit(1);
	}
}

int	player(t_game *data)
{
	int		img_size;
	char	*move_str;

	img_size = UNIT;
	data->player_img[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img0.xpm", &img_size, &img_size);
	data->player_img[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img1.xpm", &img_size, &img_size);
	data->player_img[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img2.xpm", &img_size, &img_size);
	data->player_img[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img3.xpm", &img_size, &img_size);
	data->player_img[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_img4.xpm", &img_size, &img_size);
	get_player_img(data);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	draw_background(data);
	move_str = ft_strjoin("Move count: ", ft_itoa(data->move_count));
	mlx_string_put(data->mlx_ptr, data->mlx_win, 1, 15, 0x00FF00, move_str);
	free(move_str);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->player_img[data->current_p_img], data->player_x, data->player_y);
	data->current_p_img = (data->current_p_img + 1) % 12;
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
		find_player_position(&data);
		find_enemy_position(&data);
		mlx_hook(data.mlx_win, 17, 0, exitt, &data);
		mlx_hook(data.mlx_win, 2, 0, key_handle, &data);
		mlx_loop_hook(data.mlx_ptr, player, &data);
		mlx_loop(&data);
	}
	return (ft_printf("Error\nWrong arguman number.\n"), 0);
}
