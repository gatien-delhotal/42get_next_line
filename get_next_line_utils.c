/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/14 18:14:25 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_append(char *s1, char *s2)
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

char	*readline(char	*buffer)
{
	
}
