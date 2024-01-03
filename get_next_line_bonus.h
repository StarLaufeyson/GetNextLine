/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:36 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 19:26:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

size_t  ft_strlen(const char *s);
char    ft_strjoin(char const *s1, char const *s2);
char    ft_strchr(const char *s, int c);
char    ft_substr(const char *s, unsigned int start, size_t length);
char    get_next_line(int fd);

# endif
