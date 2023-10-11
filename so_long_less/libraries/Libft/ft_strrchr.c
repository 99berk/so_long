/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:48:36 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/11 16:31:27 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;	

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
