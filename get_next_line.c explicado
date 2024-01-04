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

/*size_t	ft_strlen(const char *str)
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
}*/
//Esta función get_next_line utiliza un buffer estático para almacenar los datos leídos y se encarga 
de leer una línea completa del descriptor de archivo dado (fd). La línea leída se almacena en la variable 
line, que es un puntero a una cadena de caracteres (char **line). Además, maneja la gestión de memoria adecuada 
y verifica condiciones de error durante la ejecución.

int get_next_line(int fd, char **line)
{
// Almacena el buffer estático entre llamadas para gestionar la lectura
    static char *buffer;
// Variable temporal para gestionar la memoria
    char        *temp;
 // Variable para almacenar la cantidad de bytes leídos
    int         bytes_read;
// Verifica condiciones de entrada
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
// Si buffer no existe, inicialízalo con una cadena vacía
    if (!buffer)
        buffer = ft_strdup("");
 // Lee una línea del archivo y actualiza el buffer
    bytes_read = read_line(fd, &buffer);
    // Maneja errores de lectura
    if (bytes_read < 0)
        return (-1);
// Si no se leyeron más bytes y el buffer está vacío, llegamos al final del archivo
    if (bytes_read == 0 && ft_strlen(buffer) == 0)
    {
        free(buffer);
        buffer = NULL;
        return (0);
    }
// Obtiene la línea del buffer y la asigna a la variable line
    *line = get_line(&buffer);
// Guarda el estado del buffer antes de la línea leída
    temp = buffer;
 // Actualiza el buffer para que comience después de la línea leída
    buffer = ft_strdup(buffer + ft_strlen(*line) + 1);
// Libera la memoria anterior del buffer
    free (temp);
// Indica que se ha leído una línea exitosamente
    return (1);
}

// read_line se encarga de leer el archivo (descriptor de archivo fd) en bloques de tamaño definido por 
BUFFER_SIZE hasta que se encuentra un salto de línea o no hay más bytes que leer. Los bytes leídos se 
agregan al final del buffer, y la función continúa leyendo hasta que se completa una línea. La función 
devuelve la cantidad de bytes leídos en la última iteración.
int read_line(int fd, char **buffer)
{
 // Variable temporal para gestionar la memoria
    char    *temp;
 // Buffer temporal para almacenar los bytes leídos del archivo
    char    read_buffer[BUFFER_SIZE];
 // Variable para almacenar la cantidad de bytes leídos en una iteración
    int     bytes_read;

// Lee el archivo en bloques de tamaño BUFFER_SIZE hasta que no hay más bytes o se encuentra un salto de línea
    while ((bytes_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
    {
	// Agrega un terminador nulo al final de los bytes leídos para formar una cadena de caracteres
        read_buffer[bytes_read] = '\0';
	// Guarda el estado actual del buffer
        temp = *buffer;
	// Combina el contenido actual del buffer con los bytes recién leídos
        *buffer = ft_strjoin(*buffer, read_buffer);
	// Libera la memoria del buffer anterior
        free(temp);
	// Si se encuentra un salto de línea, termina la lectura de la línea
        if (ft_strchr(*buffer, '\n'))
            break;
    }
 // Devuelve la cantidad de bytes leídos en la última iteración
    return (bytes_read);
}

//Esta función get_line toma un puntero a un puntero (char **buffer) que apunta al buffer 
principal. La función utiliza un bucle para encontrar la longitud de la línea, buscando un 
salto de línea ('\n') o el final de la cadena ('\0'). Luego, utiliza una función como ft_substr 
para extraer la línea del buffer original y la asigna a la variable line. Finalmente, devuelve la línea extraída
char    *get_line(char **buffer)
{
// Variable para almacenar la línea extraída
    char    *line;
// Variable para almacenar la longitud de la línea
    int     length;

    lenght = 0;
// Encuentra la longitud de la línea buscando un salto de línea o el final de la cadena
    while ((*buffer)[length] != '\n' && (*buffer)[length] '\0')
        length++;
// Extrae la línea utilizando ft_substr 
    line = ft_substr(*buffer, 0, length);
// Devuelve la línea extraída
    return (line);
}
