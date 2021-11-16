# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 18:24:26 by ioleinik          #+#    #+#              #
#    Updated: 2021/11/16 13:09:26 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= cub3D

LIB_PATH	= ./libft
INCL_PATH	= ./libft

LIBRARY		= libft.a

MINI_PATH	= ./minilibx-linux
MINI_INCL	= ./minilibx-linux

MAKE		= make

SRC			= main.c parsing.c pars_path.c pars_map.c clean_up.c pars_fc.c

OBJ			= ${SRC:.c=.o}

LINKS		= -I$(INCL_PATH) \
			-I$(MINI_INCL) \
			-L $(MINI_PATH) -lmlx \
			-L $(LIB_PATH) -lft \
			-lX11 -lXext -lm

all:		$(LIBRARY) $(NAME)


$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)
			$(MAKE) -C $(MINI_PATH)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LINKS) 

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIB_PATH) fclean
			$(MAKE) -C $(MINI_PATH) clean

re:			fclean all
#Command runs norminette only for my files, not on mlx library
norm:
			norminette libft/
			norminette $(SRC) || true

.PHONY: all clean fclean re norm