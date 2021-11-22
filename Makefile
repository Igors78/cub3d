CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= cub3d

LIB_PATH	= ./libft
INCL_PATH	= ./libft

LIBRARY		= libft.a

MINI_PATH	= ./minilibx-linux
MINI_INCL	= ./minilibx-linux

MAKE		= make

SRC			= clean_up.c \
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