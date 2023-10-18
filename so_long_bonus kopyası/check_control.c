/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:29:38 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/18 17:35:16 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libraries/Libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include <unistd.h>

int	check_map_borders(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[0][y])
		if (map[0][y++] != '1')
			return (ft_printf("Error\nWrong map borders."), 0);
	x = 0;
	while (map[x])
		x++;
	y = 0;
	while (map[x - 1][y])
		if (map[x - 1][y++] != '1')
			return (ft_printf("Error\nWrong map borders."), 0);
	x = 0;
	while (map[x])
	{
		if (map[x][0] != '1' || map[x][y - 1] != '1')
			return (ft_printf("Error\nWrong map borders."), 0);
		x++;
	}
	return (1);
}

int	check_player_count(char **map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
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
		return (ft_printf("Error\nWrong player count."), 0);
	return (1);
}

int	check_exit_count(char **map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'E')
				count++;
		y++;
	}
	if (count != 1)
		return (ft_printf("Error\nWrong exit count."), 0);
	return (1);
}

int	check_map_characters(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == '0' || map[y][x] == '1'
				|| map[y][x] == 'P' || map[y][x] == 'E'
				|| map[y][x] == 'C' || map[y][x] == 'F'))
				return (ft_printf("Error\nWrong map characters."), 0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map_rectangular(char **map)
{
	int		y;
	size_t	width;

	if (!map[0])
		return (0);
	width = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != width)
			return (ft_printf("Error\nWrong map shape."), 0);
		y++;
	}
	return (1);
}
