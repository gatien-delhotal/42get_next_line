/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/28 05:07:26 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, int n)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < n)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*strn_append(char *s1, char *s2, int n, char must_free)
{
	int		i;
	int		j;
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
	if (must_free)
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
