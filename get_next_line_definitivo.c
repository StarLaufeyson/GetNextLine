/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluno-la <eluno-la@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:45:40 by eluno-la          #+#    #+#             */
/*   Updated: 2024/01/10 17:51:58 by eluno-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*temp;
	char		*dest;
	int			bytes_read;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			return (free(buffer), buffer = NULL, NULL);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_strdup("");
	bytes_read = read_line(fd, &buffer);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0 && ft_strlen(buffer) == 0)
		return (free(buffer), buffer = NULL, NULL);
	temp = ft_strdup(buffer);
	free(buffer);
	dest = get_return(&temp);
	buffer = get_keeper(&temp);
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
