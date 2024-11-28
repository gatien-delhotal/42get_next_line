/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/28 03:09:50 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strncpy(char *src, char *dst, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dst[i] = src[i];
	dst[i] = 0;
}

char	*ft_strndup(char *s, size_t n)
{
	char	*res;

	if (n == 0)
		return (NULL);
	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_strncpy(s, res, n);
	return (res);
}

char	*strn_append(char *s1, char *s2, size_t n, char aled)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
		return (ft_strndup(s2, n));
	if (!s2)
		return (s1);
	res = (char *) malloc(ft_strlen(s1) + n + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	if (aled)
		free(s1);
	j = 0;
	while (j < n)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}

