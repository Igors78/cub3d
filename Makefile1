# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 09:38:06 by khanakgulat       #+#    #+#              #
#    Updated: 2021/11/22 15:34:48 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FILES = clean_up.c \
		cub.c \
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
		raycasting4.c \
		raycasting5.c

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

norme: 
	norminette $(FILES) libft/ || true

re: fclean all
