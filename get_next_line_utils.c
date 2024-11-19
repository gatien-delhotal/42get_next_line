/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/19 17:33:56 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
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

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!s1)
	{
		res = ft_strndup(s2, size2);
		free(s2);
		return (res);
	}
	if (!s2)
		return (ft_strndup(s1, size1));
	res = (char *) malloc(size1 + size2 + 1);
	if (!res)
	{
		free(s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
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

	if (n == 0)
		return (NULL);
	res = (char *) malloc(n + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	trim_endline(char **s, char *buffer, size_t size)
{
	size_t		i;
	size_t		mem_size;
	char		*temp;
	static char	*mem = NULL;

	mem_size = ft_strlen(mem);
	if (!size && !mem_size)
		return (0);
	temp = str_append(mem, ft_strndup(buffer, size));
	if (!temp)
		return (0);
	size += mem_size;
	i = 0;
	while (i < size && temp[i] != '\n')
		i++;
	*s = str_append(*s, ft_strndup(temp, i + 1));
	if (i < size)
		mem = ft_strndup(&temp[i + 1], size - i - 1);
	else if (mem)
		free(mem);
	free(temp);
	return (i - mem_size);
}
