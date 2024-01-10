# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 11:57:10 by marvin            #+#    #+#              #
#    Updated: 2024/01/10 11:57:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = proyecto_get_next_line

SRC = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRCS:%.c=o.)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	?gcc $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c 
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
