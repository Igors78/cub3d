# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:38:06 by khanakgulat       #+#    #+#              #
#    Updated: 2021/11/22 10:15:35 by khanakgulat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FILES = clean_up.c \
		cub.c \
		debug_print.c \
		fill.c \
		init_graphics.c \
		pars_doubles.c \
		pars_fc.c \
		pars_map.c \
		pars_path.c \
		parsing.c \
		raycasting1.c \
		raycasting2.c \
		raycasting3.c \
		raycasting4.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FILES) libft/libft.a -framework OpenGL -framework AppKit -lmlx -Lmlx -o $(NAME)

clean:
	make -C ./libft fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all
