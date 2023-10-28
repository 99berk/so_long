/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:05 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/28 12:56:13 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libraries/Libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/get_next_line/get_next_line.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	return (ft_strlen(map[0]));
}

int	ctrl(char *map_holder)
{
	int	len;

	if (!*map_holder)
	{
		free(map_holder);
		ft_printf("Error\nEmpty file or new line on the top.\n");
		exit(1);
	}
	len = ft_strlen(map_holder);
	if (map_holder[len - 1] == '\n')
	{
		ft_printf("Error\nMap has a new line.\n");
		free(map_holder);
		exit(1);
	}
	return (0);
}

char	**read_map(char *file)
{
	char	**map;
	char	*map_holder;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nThe map file doesn't exist.\n"), NULL);
	map_holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line || ft_strcmp(line, "\n") == 0)
			break ;
		tmp = map_holder;
		map_holder = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	ctrl(map_holder);
	map = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (map);
}

int	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
	{
		ft_printf("Error\nWrong file extension.\n");
		exit(1);
		return (0);
	}
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	ft_printf("Error\nWrong file extension.\n");
	exit(1);
	return (0);
}
