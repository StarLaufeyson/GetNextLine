# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eluno-la <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 17:43:20 by eluno-la          #+#    #+#              #
#    Updated: 2023/11/06 17:48:36 by eluno-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = proyecto_get_next_line

SRC = get_next_line.c */main.c*/
OBJ = $(SRC:.c=.o)

/*LIBFT = libft/libft.a*/

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft -I.

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -L libft -lft

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
