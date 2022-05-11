# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oairola <oairola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:43:10 by oairola           #+#    #+#              #
#    Updated: 2022/01/28 09:29:14 by oairola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCES = create_grid.c main.c populate.c printer.c freer.c \
get_next_line.c freer_grid.c safe_check.c ft_error_exit.c \
ft_grid_dealer.c ft_piece_checker.c file_reader.c dot_dealer.c \
freer_int.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -Wall -Wextra -Werror -c $(SOURCES)
	gcc -o $(NAME) $(OBJECTS) -L./libft -lft

clean:
	/bin/rm -f $(OBJECTS)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re:fclean all
