/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:52:22 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/06 13:08:28 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*str;

	counter = 0;
	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[counter] != '\0')
	{
		str[counter] = s1[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
