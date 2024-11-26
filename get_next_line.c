/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:18 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/26 16:49:27 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		bytes_read;

	if (fd < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	while (trim_endline(&line, buffer, bytes_read) == BUFFER_SIZE)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(int ac, char **av)
{
	int fd = open("./txt", O_RDONLY);
	int	i = -1;
	int repeat = 1;
	char *line;
	if (ac > 1)
		repeat = av[1][0] - '0';
	while (++i < repeat)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
}
