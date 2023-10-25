/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_upload_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:49 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/25 17:46:12 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "./minilibx/mlx.h"
#include "./libraries/ft_printf/ft_printf.h"

void	get_background_img(t_game *data)
{
	int		img_size;

	img_size = UNIT;
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/wall_img.xpm", &img_size, &img_size);
	if (!data->wall_img)
	{
		ft_printf("Error\nCould not load wall image.\n");
		exitt(data);
	}
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/floar_img.xpm", &img_size, &img_size);
	if (!data->floor_img)
	{
		ft_printf("Error\nCould not load floor image.\n");
		exitt(data);
	}
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit_img.xpm", &img_size, &img_size);
	if (!data->exit_img)
	{
		ft_printf("Error\nCould not load exit image.\n");
		exitt(data);
	}
}

void	get_collectible_img(t_game *data)
{
	int		img_size;

	img_size = UNIT;
	data->collectible_img[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible_img.xpm", &img_size, &img_size);
	data->collectible_img[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible_img1.xpm", &img_size, &img_size);
	data->collectible_img[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible_img2.xpm", &img_size, &img_size);
	data->collectible_img[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible_img3.xpm", &img_size, &img_size);
	if (!data->collectible_img[data->collectible_current_img])
	{
		ft_printf("Error\nCould not load collectible image.\n");
		exitt(data);
	}
}

void	img_uploud(t_game *data)
{
	get_background_img(data);
	get_collectible_img(data);
}
