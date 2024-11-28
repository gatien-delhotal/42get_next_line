/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:18 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/28 03:16:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_destroy_mem(char *mem)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		mem[i] = 0;
}

char	*ft_fix_mem(char *temp, char *mem, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = temp[i];
	free(mem);
	dest[i] = 0;
	return (dest);
}

int	trim_endline(char **s, char *buffer, size_t size)
{
	size_t		i;
	size_t		mem_size;
	char		*temp;
	static char	*mem = NULL;

	if (size && !mem)
	{
		mem = (char *) malloc(BUFFER_SIZE);
		if (mem)
			mem[0] = '\0';
	}
	mem_size = ft_strlen(mem);
	if (!mem || (!size && !mem_size))
		return (0);
	temp = strn_append(mem, buffer, size, 0);
	size += mem_size;
	i = 0;
	while (i < size && temp[i] != '\n')
		i++;
	*s = strn_append(*s, temp, i + 1, 1);
	mem[0] = '\0';
	if (i < size)
		ft_destroy_mem(mem);
	if (i < size)
		mem = ft_fix_mem(&temp[i + 1], mem, size - i - 1);
	if (!mem[0])
	{
		free(mem);
		mem = NULL;
	}
	free(temp);
	return (i - mem_size);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
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
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
	}
	free(buffer);
	return (line);
}

/*
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
*/
