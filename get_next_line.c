/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluno-la <eluno-la@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:34 by eluno-la          #+#    #+#             */
/*   Updated: 2024/01/04 18:13:34 by eluno-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Esta función get_next_line utiliza un buffer estático para almacenar los datos leídos y se encarga 
de leer una línea completa del descriptor de archivo dado (fd). La línea leída se almacena en la variable 
line, que es un puntero a una cadena de caracteres (char **line). Además, maneja la gestión de memoria adecuada 
y verifica condiciones de error durante la ejecución*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	bytes_read = read_line(fd, &buffer);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0 && ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	temp = buffer;
	buffer = ft_strdup(buffer + ft_strlen(get_line(&temp)) + 1);
	free(temp);
	return (get_line(&temp));
}

/*BUFFER_SIZE hasta que se encuentra un salto de línea o no hay más bytes que leer. Los bytes leídos se 
agregan al final del buffer, y la función continúa leyendo hasta que se completa una línea. La función 
devuelve la cantidad de bytes leídos en la última iteración.*/

int	read_line(int fd, char **buffer)
{
	char	*temp;
	char	read_buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			read_buffer[bytes_read] = '\0';
			temp = *buffer;
			*buffer = ft_strjoin(*buffer, read_buffer);
			free(temp);
			if (!buffer)
				return (-1); //memory allocation failure
		}
		if (ft_strchr(*buffer, '\n') || bytes_read == 0)
			break ;
	}
	return (bytes_read);
}
/*Esta función get_line toma un puntero a un puntero (char **buffer) que apunta al buffer 
principal. La función utiliza un bucle para encontrar la longitud de la línea, buscando un 
salto de línea ('\n') o el final de la cadena ('\0'). Luego, utiliza una función como ft_substr 
para extraer la línea del buffer original y la asigna a la variable line. Finalmente, devuelve la línea extraída*/

char    *get_line(char **buffer)
{
    char    *line;
    int     len;

    len = 0;
    while ((*buffer)[len] != '\n' && (*buffer)[len] != '\0')
        len++;
    line = ft_substr(*buffer, 0, len);
    if (!line)
	    return (NULL); //Memory allocation failure
    return (line);
}
