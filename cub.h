
#ifndef CUB_H
# define CUB_H

# define MAX_X 800
# define MAX_Y 570

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>

typedef struct s_fdf
{
	int		w;
	int		h;
	int		**a;
	int		**c;
	int		x;
	float	x1;
	float	x2;
	int		y;
	float	y1;
	float	y2;
	int		z;
	int		z1;
	int		color;
	int		zoom;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				*t_fdf;

void	read_map(char *map, t_fdf d);
void	draw_line(t_fdf d);
void	put_pix(t_fdf d, int x, int y, int color);
void	plot(t_fdf d);
void	init_colors(t_fdf d);
void	isometr(t_fdf d);
void	reset_coord(t_fdf d);

#endif