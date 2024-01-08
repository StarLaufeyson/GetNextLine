/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluno-la <eluno-la@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:35:54 by eluno-la          #+#    #+#             */
/*   Updated: 2023/10/26 19:30:27 by eluno-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
/*void	*ft_calloc(size_t num_elements, size_t size)
{
	size_t total_size;
	void *ptr;
	
	total_size = num_elements * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char	*str;

	if (n == 0)
		return ;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
	return ;
}*/
#include    "get_next_line.h"

char    *get_next_line(int fd)
{
int     bytes_read;
char    *cup_buffer;    

cup_buffer = ft_calloc (4 + 1, sizeof(char));
if (cup_buffer == NULL)
    return (NULL);
//buffer = malloc (3 + 1 * sizeof(char));
bytes_read = read(fd, cup_buffer, 3);
if (bytes_read <= 0)
    return (NULL);
return (cup_buffer);
}

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("archivo.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
/*int	main(void)
{
	int		fd;
	char	buff[70];
	ssize_t	nr_bytes;

	fd = open("/Users/eluno-la/GETNEXT/miFichero", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo \n");
	}
	else
	{
		nr_bytes = read(fd, buff, sizeof(buff));
		close(fd);
		if (nr_bytes == 0)
		{
			printf("archivo vacio \n");
		}
		else
		{
			printf("Number of characters %d, content: %s\n", (int)nr_bytes, buff);
		}
	}
	return (0);
}*/
