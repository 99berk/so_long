/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:39:12 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/08 15:19:15 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (*(s + i) && *(s + i) != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_getword(char const *s, char c, int i)
{
	char	*str;
	int		len;
	int		j;

	len = ft_wlen(s, c, i);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (*(s + i) != 0 && *(s + i) != c)
	{
		str[j] = *(s + i);
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_countofword(char const *s, char c)
{
	int	countword;
	int	i;

	i = 0;
	countword = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
		{
			i++;
		}
		if (*(s + i) != 0)
		{
			countword++;
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (countword);
}

static char	**ft_allfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc((ft_countofword(s, c) + 1) * sizeof(char *));
	if (!str)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		if (*(s + i))
		{
			str[j] = ft_getword(s, c, i);
			if (!str[j++])
				return (ft_allfree(str));
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (str[j] = 0, str);
}
