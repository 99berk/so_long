/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:18:26 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/11 18:09:52 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libraries/ft_printf/ft_printf.h"

int exitt (t_game *data)
{   (void)data;
    exit (1);
    return (0);
}

int count_collectibles(char **map)
{
    int y = 0;
    int x = 0;
    int count = 0;
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
    return count;
}

int key_handle(int key, t_game *data)
{
    int new_x = data->player_x;
    int new_y = data->player_y;
    
    if (key == 53) // ESC tuşu
        exitt(data);
    if (key == 13) // Yukarı ok tuşu
        data->player_y -= UNIT;
    if (key == 1) // Aşağı ok tuşu
        data->player_y += UNIT;
    if (key == 0) // Sol ok tuşu
        data->player_x -= UNIT;
    if (key == 2) // Sağ ok tuşu
        data->player_x += UNIT;
    if (data->map[data->player_y / UNIT][data->player_x / UNIT] == '1') 
    {
        data->player_x = new_x;
        data->player_y = new_y;
    }
    else
    {
        data->move_count++;
        ft_printf("Move count: %d\n", data->move_count);
    }
    if (data->map[data->player_y / UNIT][data->player_x / UNIT] == 'C')
            data->map[data->player_y / UNIT][data->player_x / UNIT] = '0'; // toplanabilir öğeyi yok edin.
    data->collectibles_left = count_collectibles(data->map);
    if (data->map[data->player_y / UNIT][data->player_x / UNIT] == 'E' && data->collectibles_left == 0)
        exitt(data);
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    draw_background(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player_img, data->player_x, data->player_y);
    
    return (0);
}

void    find_player_position(t_game *data)
{
    int y = 0;
    int x = 0;

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

int     get_map_height(char **map)
{
    int height = 0;

    while (map[height])
        height++;
    return (height);
}

int     get_map_width(char **map)
{
    return (ft_strlen(map[0]));
}

int player(t_game *data)
{
    int img_width = UNIT;
    int img_height = UNIT;

    data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, "./images/1p1.xpm", &img_width, &img_height);
    if (!data->player_img)
    {
        ft_printf("Error loading player image.\n");
        exit(1);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player_img, data->player_x, data->player_y);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        t_game data;
        
        check_file_extension(av[1]);
        data.map = read_map(av[1]);
        
        if (!data.map || !check_map_characters(data.map) || !check_map_rectangular(data.map) || !check_map_borders(data.map) || !check_player_count(data.map) || !check_exit_count(data.map))
            exit(1);
    
        int map_width = get_map_width(data.map);
        int map_height = get_map_height(data.map);
        
        data.mlx_ptr = mlx_init();
        data.mlx_win = mlx_new_window(data.mlx_ptr, UNIT * map_width, UNIT * map_height, "So_long");
        draw_background(&data);
        find_player_position(&data);
        player(&data);
        mlx_hook(data.mlx_win, 17, 0, exitt, &data);
        mlx_hook(data.mlx_win, 2, 0, key_handle, &data);
        mlx_loop(&data);
    }
    return (ft_printf("Error: Wrong arguman number.\n"), 0);
}