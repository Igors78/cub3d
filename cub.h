/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:16 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/19 10:51:42 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define MAX_X 500
# define MAX_Y 500

typedef struct s_player
{
	int		posx;
	int		posy;
	float	O;
	int		startx;
	int		starty;
	char	start_dir;
}		t_player;

typedef struct s_tex
{
	void	*img;
	int		img_w;
	int		img_h;
	char	*path;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_tex;

typedef struct s_cub
{
	int			f_color[3];
	int			c_color[3];
	int			hex_floor;
	int			hex_ceil;
	char		**map_strings;
	int			**map;
	int			map_h;
	int			map_w;
	int			quant_par;
	int			flag;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
	t_player	g_player;
}			t_cub;

void	read_config(char *path, t_cub *d);
void	parse_path(char **str, t_cub *d);
void	clean_up(t_cub *d);
void	parse_map(int fd, t_cub *d);
void	inv_map(t_cub *d);
void	inv_color(t_cub *d);
void	parse_floor(char **arr, t_cub *d);
void	parse_ceil(char **arr, t_cub *d);
void	parse_doubles(char **a, t_cub *d);
void	debug_print(t_cub *d);
void	exit_color(char **arr, char **col, t_cub *d);
void	fill_map_color(t_cub *d);
void	print_arr(char **arr);
void	init_graphics(t_cub *d);
void	put_pix(t_cub *d, int x, int y, int color);

#endif
