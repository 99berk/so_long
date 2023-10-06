/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:22:13 by bakgun            #+#    #+#             */
/*   Updated: 2023/10/06 13:59:09 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void	*ft_free_stash(char **stash, int create_line);

#endif
