/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:18 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/14 21:11:17 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = malloc(BUFFER_SIZE);
	line = NULL;
	read(fd, buffer, BUFFER_SIZE);
	while (trim_endline(line, buffer) == BUFFER_SIZE)
		read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int fd = open("./txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
