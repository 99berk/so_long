/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:47:49 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/06 13:57:53 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	calc_len;

	calc_len = ft_strlen_gnl(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > calc_len)
		len = calc_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < calc_len && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (create_line == 1)
	{
		line = ft_strdup_gnl(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}
