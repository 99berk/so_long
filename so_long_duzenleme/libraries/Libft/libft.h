/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:05:21 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/06 13:40:33 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

#endif
