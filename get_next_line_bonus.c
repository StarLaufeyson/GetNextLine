/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:47:46 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 18:47:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line_bonus.h"

//#include <stdio.h>
#include "get_next_line_bonus.h"

int	read_line(int fd, char **buffer)
{
	char	*temp;
	char	read_buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (bytes_read);
		if (bytes_read > 0)
		{
			read_buffer[bytes_read] = '\0';
			temp = ft_strdup(*buffer);
			free(*buffer);
			*buffer = ft_strjoin(temp, read_buffer);
			free(temp);
			if (!buffer)
				return (-1);
		}
		if (ft_strchr(*buffer, '\n') || bytes_read == 0)
			break ;
	}
	return (bytes_read);
}

char	*get_return(char **buffer)
{
	char	*line;
	int		len;

	len = 0;
	while ((*buffer)[len] != '\n' && (*buffer)[len] != '\0')
		len++;
	if ((*buffer)[len] == '\0')
		line = ft_substr(*buffer, 0, (len));
	else
		line = ft_substr(*buffer, 0, (len + 1));
	if (!line)
		return (NULL);
	return (line);
}

char	*get_keeper(char **buffer)
{
	char	*line;
	int		len;

	len = 0;
	while ((*buffer)[len] != '\n' && (*buffer)[len] != '\0')
		len++;
	line = ft_substr(*buffer, (len + 1), (ft_strlen(*buffer) - len - 1));
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*temp;
	char		*dest;
	int			bytes_read;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			return (free(buffer[fd]), buffer[fd] = NULL, NULL);
		return (NULL);
	}
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	bytes_read = read_line(fd, &buffer[fd]);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0 && ft_strlen(buffer[fd]) == 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	temp = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	dest = get_return(&temp);
	buffer[fd] = get_keeper(&temp);
	return (free(temp), dest);
}
/*
int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	i = 10;
	while (i--)
	{
		if (i == 7)
			line = get_next_line(48);
		else
			line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
