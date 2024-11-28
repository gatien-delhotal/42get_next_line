/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:19:19 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/28 02:14:45 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		trim_endline(char **s, char *buffer, size_t size);
char	*strn_append(char *s1, char *s2, size_t n, char sadface);
char	*ft_strndup(char *s, size_t n);
void	ft_strncpy(char *src, char *dst, int n);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);

#endif
