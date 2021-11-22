/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:16 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/22 14:28:11 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "mlx/mlx.h"
// # include "mlx/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define MAX_X 500
# define MAX_Y 500

typedef struct s_player
{
	int		posx;
	int		posy;
	float	o;
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

void		read_config(char *path, t_cub *d);
void		parse_path(char **str, t_cub *d);
void		clean_up(t_cub *d);
void		parse_map(int fd, t_cub *d);
void		inv_map(t_cub *d);
void		inv_color(t_cub *d);
void		parse_floor(char **arr, t_cub *d);
void		parse_ceil(char **arr, t_cub *d);
void		parse_doubles(char **a, t_cub *d);
void		debug_print(t_cub *d);
void		exit_color(char **arr, char **col, t_cub *d);
void		fill_map_color(t_cub *d);
void		print_arr(char **arr);
void		init_graphics(t_cub *d);
void		put_pix(t_cub *d, int x, int y, int color);
int			max(int a, int b);
int			min(int a, int b);
float		check_limits(float o);
int			xdist_quad1(float o, int x, int y, t_cub *d);
int			ydist_quad1(float o, int x, int y, t_cub *d);
int			xdist_quad2(float o, int x, int y, t_cub *d);
int			ydist_quad2(float o, int x, int y, t_cub *d);
int			xdist_quad3(float o, int x, int y, t_cub *d);
int			ydist_quad3(float o, int x, int y, t_cub *d);
int			xdist_quad4(float o, int x, int y, t_cub *d);
int			ydist_quad4(float o, int x, int y, t_cub *d);
int			which_wall(int dists_fov[250][2], int i, t_cub *d);
void		paint_screen(int dists_fov[250][2], int i, t_cub *d);
int			set_dists_wall(int *x_d, int *y_d, float o, t_cub *d);
int			set_dists_wall2(int *x_d, int *y_d, float o, t_cub *d);
int			cast_rays(int x_dist, int y_dist, int mindist, t_cub *d);
float		angle_change(int dir, float ang);
void		keys_aw(int key, t_cub *d, int x, int y);
void		keys_ds(int key, t_cub *d, int x, int y);
void		coord_to_pixel(t_cub *d);
float		spawn_angle(char dir);
static int	key_event(int button, void *param);
static int	ft_checkarg(char *str);
static void	init_data(t_cub *d);

#endif
