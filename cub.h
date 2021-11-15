/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:16 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/15 19:42:37 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>

# define MAX_X 800
# define MAX_Y 570
# define EMPTY 2
# define N 3
# define S 4
# define W 5
# define E 6

typedef struct s_cub
{
	int		f_color[3];
	int		c_color[3];
	int		**map;
	int		quant_par;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
}			*t_cub;

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

void	read_config(char *path, t_cub d);
void	parse_path(char **str, t_cub d);
void	clean_up(t_cub d);

#endif
