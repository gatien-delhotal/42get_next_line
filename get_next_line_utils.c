/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/14 21:17:19 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*str_append(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
		return (s2);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *) malloc(size1 + size2 + 1);
	if (!res)
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	free(s2);
	res[i + j] = 0;
	return (res);
}

static char	*ft_strndup(char *s, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *) malloc(n + 1);
	i = -1;
	while (++i < n)
		res[i] = s[i];
	res[i] = 0;
	return (res);
}

int	trim_endline(char *s, char *buffer)
{
	int			i;
	static char	*mem = NULL;

	if (!mem)
		mem = (char *) malloc(4096);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		mem = &s[i + 1];
	else
		free(mem);
	s = str_append(mem, ft_strndup(s, i));
	return (ft_strlen(s));
}
