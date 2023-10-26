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

int	main(void)
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
}
