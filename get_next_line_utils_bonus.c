/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:37:04 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 19:37:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////Determina la longitud de una cadena de caracteres
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

////Extrae una subcadena de una cadena previamente dada
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = len;
	if (start >= s_len)
		return (ft_strdup(""));
	if (sub_len > (s_len - start))
		sub_len = s_len - start;
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, sub_len + 1);
	return (substr);
}

//concatena 2 cadenas s1 y s2 y devuelve una cadena resultante (no requiere conocer tamaño máximo buffer)
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

////Busca última ocurrencia del caracter 'c' en la cadena 's'
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

//#include	<stdio.h>
//copia 'n' bytes de origen/src a destino/dest
void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	char	*d;
	const char	*s;
	size_t	i;

	d = dest;
	s = src;
	i = 0;
	while (i < length)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
