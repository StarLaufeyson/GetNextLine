/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:02:10 by marvin            #+#    #+#             */
/*   Updated: 2023/12/17 17:02:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*duplicate;
	
	length = ft_strlen(s);
	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			duplicate[i] = s[i];
			i++;
		}
		duplicate[i] = '\0';
	}
	return (duplicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (result == NULL)size_t	total_len;
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

int get_next_line(int fd, char **line)
{
    static char *buffer;
    char        *temp;
    int         bytes_read;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!buffer)
        buffer = ft_strdup("");
    bytes_read = read_line(fd, &buffer);
    if (bytes_read < 0)
        return (-1);
    if (bytes_read == 0 && ft_strlen(buffer) == 0)
    {
        free(buffer);
        buffer = NULL;
        return (0);
    }
    *line = get_line(&buffer);
    temp = buffer;
    buffer = ft_strdup(buffer + ft_strlen(*line) + 1);
    free (temp);
    return (1);
}

int read_line(int fd, char **buffer)
{
    char    *temp;
    char    read_buffer[BUFFER_SIZE];
    int     bytes_read;

    while ((bytes_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
    {
        read_buffer[bytes_read] = '\0';
        temp = *buffer;
        *buffer = ft_strjoin(*buffer, read_buffer);
        free(temp);
        if (ft_strchr(*buffer, '\n'))
            break;
    }
    return (bytes_read);
}

char    *get_line(char **buffer)
{
    char    *line;
    int     length;

    lenght = 0;
    while ((*buffer)[length] != '\n' && (*buffer)[length] '\0')
        length++;
    line = ft_substr(*buffer, 0, length);
    return (line);
}
