/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:18 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/15 17:44:39 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	size_t	bytes_read;

	buffer = malloc(BUFFER_SIZE);
	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (trim_endline(line, buffer, bytes_read) == BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int fd = open("./txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
