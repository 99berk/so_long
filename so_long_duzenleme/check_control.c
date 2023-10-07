/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:29:38 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/07 18:31:08 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libraries/Libft/libft.h"
#include <unistd.h>

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