/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:18:26 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/06 18:11:19 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exitt (t_game *data)
{   (void)data;
    exit (1);
    return (0);
}

#include <fcntl.h>
char    **read_map (char *file)
{
    char    **map;
    char    *map_holder;
    char    *line;
    char    *tmp;
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    map_holder = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        tmp = map_holder;
        map_holder = ft_strjoin(tmp, line);
        free(line);
        free(tmp);
    }
    map = ft_split(map_holder, '\n');
    free(map_holder);
    close(fd);
    return (map);
}

void draw_background(t_game *data)
{
    void *img_ptr;
    int width = UNIT * 16;
    int height = UNIT * 8;

    img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "374852-2.xpm", &width, &height);
    
    if (img_ptr)
        mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img_ptr, 0, 0);
    else
        write(1, "Error loading background image.\n", 32);

    int y = 0;
    int x = 0;
    int w = UNIT;
    int h = UNIT;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
            {
                data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm", &w, &h);
                if (!data->wall_img)
                    ft_printf("Error loading wall image.\n");
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->wall_img, x * UNIT, y * UNIT);
            }
            else if (data->map[y][x] == 'C')
            {
                data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, "money.xpm", &w, &h);
                if (!data->collectible_img)
                   ft_printf("Error loading collectible image.\n");
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collectible_img, x * UNIT, y * UNIT);
            }
            else if (data->map[y][x] == 'E')
            {
                data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, "spacex.xpm", &w, &h);
                if (!data->exit_img)
                    ft_printf("Error loading exit image.\n");
                mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->exit_img, x * UNIT, y * UNIT);
            }
            x++;
        }
        y++;
    }
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

    // Ok tuşları için key kodları
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
    if (data->map[new_y / UNIT][new_x / UNIT] == 'C')
    {
            data->map[new_y / UNIT][new_x / UNIT] = '0'; // toplanabilir öğeyi yok edin.
    }
    
    data->collectibles_left = count_collectibles(data->map);
    if (data->map[data->player_y / UNIT][data->player_x / UNIT] == 'E' && data->collectibles_left == 0)
    {
        exitt(data);
        return (0);
    }

    // Pencerenin güncellenen konumuyla yeniden çizilmesi
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

int    check_map_borders(char **map)
{
    int y = 0;
    int x;

    // İlk satır
    while (map[0][y])
    {
        if (map[0][y] != '1')
            return (0);
        y++;
    }

    // Son satır
    x = 0;
    while (map[x])
        x++;
    y = 0;
    while (map[x - 1][y])
    {
        if (map[x - 1][y] != '1')
            return (0);
        y++;
    }

    // İlk ve son sütun
    x = 0;
    while (map[x])
    {
        if (map[x][0] != '1' || map[x][y - 1] != '1')
            return (0);
        x++;
    }
    
    return (1);
}

int    check_player_count(char **map)
{
    int y, x;
    int count = 0;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
                count++;
            x++;
        }
        y++;
    }

    if (count != 1)
        return (0);
    return (1);
}

int    check_exit_count(char **map)
{
    int y, x;
    int count = 0;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'E')
                count++;
            x++;
        }
        y++;
    }

    if (count != 1)
        return (0);
    return (1);
}

int check_map_characters(char **map)
{
    int y, x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (!(map[y][x] == '0' || map[y][x] == '1' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C'))
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int check_map_rectangular(char **map)
{
    int y;
    size_t width;

    if (!map[0])
        return (0);
    width = ft_strlen(map[0]);

    y = 1;
    while (map[y])
    {
        if (ft_strlen(map[y]) != width)
            return (0);
        y++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_game data;

    if (ac == 2)
    {
        data.map = read_map(av[1]);
        if (!data.map || !check_map_borders(data.map) || !check_player_count(data.map) || !check_exit_count(data.map) || !check_map_characters(data.map) || !check_map_rectangular(data.map))
        {
            write(1, "Error: Invalid map.\n", 20);
            exit(1);
        }
    
        int map_width = get_map_width(data.map);
        int map_height = get_map_height(data.map);
    
        int img_width = UNIT;
        int img_height = UNIT;
    
        data.mlx_ptr = mlx_init();
        data.mlx_win = mlx_new_window(data.mlx_ptr, UNIT * map_width, UNIT * map_height, "So_long");
    
        draw_background(&data);
    
        data.player_img = mlx_xpm_file_to_image(data.mlx_ptr, "elon.xpm", &img_width, &img_height);
        find_player_position(&data);
        mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.player_img, data.player_x, data.player_y);
    
        mlx_hook(data.mlx_win, 17, 0, exitt, &data);
        mlx_hook(data.mlx_win, 2, 0, key_handle, &data);
    
        mlx_loop(&data);
    }
}