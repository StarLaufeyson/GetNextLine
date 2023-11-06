/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eluno-la <eluno-la@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:06:51 by eluno-la          #+#    #+#             */
/*   Updated: 2023/10/27 13:54:46 by eluno-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

int	main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	char	buffer[1024];
	int		numbytes;
	/*comprobamos que pasan dos argumentos*/
	if (argc != 3)
	{
		printf("Uso: %s origen destino\n", argv[0]);
		exit (1);
	}
	/*abrimos los dos archivos*/
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0700);
	/*bucle de lectura/escritura*/
	while ((numbytes = read(fd1, buffer, sizeof(buffer))) > 0)
	{
		write(fd2, &buffer, numbytes);
	}
	/*cierre de archivos*/
	close(fd1);
	close(fd2);
}
