/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:34:41 by marvin            #+#    #+#             */
/*   Updated: 2023/12/17 17:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Determina la longitud de una cadena de caracteres
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
//Duplica una cadena de caracteres, asignando memoria para una nueva cadena y copiando el nuevo 
//contenido de la cadena original en la nueva memoria asignada
char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*duplicate;

	length = ft_strlen(s);
	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
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
//concatena 2 cadenas s1 y s2 y devuelve una cadena resultante (no requiere conocer tamaño máximo buffer)
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr - size);
}

//Busca última ocurrencia del caracter 'c' en la cadena 's'
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
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

//Extrae una subcadena de una cadena previamente dada
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	size_t	size;

	size = len;
	i = 0;
	if (ft_strlen(s) < start || !*s)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	ptr[len] = '\0';
	if (!ptr)
		return (NULL);
	while (len-- && s[start])
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	return (ptr);
}
