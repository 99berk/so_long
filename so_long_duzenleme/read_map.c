/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:51:05 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/07 11:01:21 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libraries/Libft/libft.h"
#include "./libraries/get_next_line/get_next_line.h"

char	**read_map(char *file)
{
	char	**map;
	char	*map_holder;
	char	*line;
	char	*tmp;
	int		fd;

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
