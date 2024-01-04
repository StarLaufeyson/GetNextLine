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

char    *ft_free(char **str)
{
    free(*str);
    *str = NULL;
    return (NULL);
}

char    *read_buffer(int fd, char *storage)
{
    int     read_value;
    char    *buffer;

    read_value = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (ft_free(&storage));
    buffer[0] = '\0';
    while (read_value > 0 && !ft_strchr(buffer, '\n'))
    {
        read_value = read(fd, buffer, BUFFER_SIZE);
        if (read_value > 0)
        {
            buffer[read_value] = '\0';
            storage = ft_strjoin(storage, buffer);
        }
    }
    free(buffer);
    if (read_value == -1)
        return (ft_free(&storage));
    return (storage);
}

char    *clean_storage(char *storage)
{
    char    *new_storage;
    char    *ptr;
    int     len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
    {
        new_storage = NULL;
        return (ft_free(&storage));
    }
    else
        len = (ptr - storage) + 1;
    if (!storage[len])
        return (ft_free(&storage));
    new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
    ft_free(&storage);
    if (!new_storage)
        return (NULL);
    return (new_storage);
}

char    *new_line(char *storage)
{
    char    *line;
    char    *ptr;
    int     len;

    ptr = ft_strchr(storage, '\n');
    len = (ptr - storage) + 1;
    line = ft_substr(storage, 0, len);
    if (!line)
        return (NULL);
    return (line);
}

char    *get_next_line(int fd)
{
    static char *storage;
    char        *line;

    if (fd < 0)
        return (NULL);
    if (!storage)
        storage = read_buffer(fd, storage);
    if (!storage)
        return (NULL);
    line = new_line(storage);
    if (!line)
        return (ft_free(&storage));
    storage = clean_storage(storage);
    return (line);
}
