/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/19 13:44:04 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define WWALL 0xff0000
#define NWALL 0x00ff00
#define EWALL 0x0000ff
#define SWALL 0xffff00

// < d > stands for data table stored in s_cub structure

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

float check_limits(float O)
{
	if (O < 0)
		O += (2 * M_PI);
	else if (O > (2 * M_PI))
		O -= (2 * M_PI);
	return (O);
}

int xdist_quad1(float O, int x, int y, t_cub *d)
{
	int x_dist;
	int dx;
	int dy;

	x_dist = 20000 * max(d->map_w, d->map_h);
	dx = (d->g_player.posx % 100); //x goes to nearest line on left
	dy = dx * tan(O);			   //diff in y depends on angle
	x = d->g_player.posx - dx;	   //x and y are the positions of the ray when intersecting a vertical line
	y = d->g_player.posy - dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[((y - 1) / 100)][(x - 1) / 100] == 1) //i-j coordinates of the block that the ray is intersecting (on the grid) :
		{
			x_dist = dx / cos(O); //length of the ray
			if (O < 0.02)
				x_dist = dx;
			break;
		}
		dx += 100; //if grid value of block is 0 (empty space), keep going to the next vertical line until intersection with grid value 1 found
		dy = dx * tan(O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy - dy;
	}
	return (x_dist);
}

int ydist_quad1(float O, int x, int y, t_cub *d)
{
	int y_dist;
	int dx;
	int dy;

	y_dist = 20000 * max(d->map_w, d->map_h);
	dy = d->g_player.posy % 100;
	dx = dy / tan(O);
	x = d->g_player.posx - dx;
	y = d->g_player.posy - dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y - 1) / 100][((x - 1) / 100)] == 1)
		{
			y_dist = dy / sin(O);
			break;
		}
		dy += 100;
		dx = dy / tan(O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy - dy;
	}
	return (y_dist);
}

int xdist_quad2(float O, int x, int y, t_cub *d)
{
	int x_dist;
	int dx;
	int dy;

	x_dist = 20000 * max(d->map_w, d->map_h);
	dx = 100 - (d->g_player.posx % 100);
	dy = dx * tan(M_PI - O);
	x = d->g_player.posx + dx;
	y = d->g_player.posy - dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[((y - 1) / 100)][(x + 1) / 100] == 1)
		{
			x_dist = dy / sin(M_PI - O);
			if (O > M_PI - 0.02)
				x_dist = dx;
			break;
		}
		dx += 100;
		dy = dx * tan(M_PI - O);
		x = d->g_player.posx + dx;
		y = d->g_player.posy - dy;
	}
	return (x_dist);
}

int ydist_quad2(float O, int x, int y, t_cub *d)
{
	int y_dist;
	int dx;
	int dy;

	y_dist = 20000 * max(d->map_w, d->map_h);
	dy = d->g_player.posy % 100;
	dx = dy / tan(M_PI - O);
	x = d->g_player.posx + dx;
	y = d->g_player.posy - dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y - 1) / 100][x / 100] == 1)
		{
			y_dist = dy / sin(M_PI - O);
			break;
		}
		dy += 100;
		dx = dy / tan(M_PI - O);
		x = d->g_player.posx + dx;
		y = d->g_player.posy - dy;
	}
	return (y_dist);
}

int xdist_quad3(float O, int x, int y, t_cub *d)
{
	int x_dist;
	int dx;
	int dy;

	x_dist = 20000 * max(d->map_w, d->map_h);
	dx = 100 - (d->g_player.posx % 100);
	dy = dx * tan(O - M_PI);
	x = d->g_player.posx + dx;
	y = d->g_player.posy + dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y / 100)][(x + 1) / 100] == 1)
		{
			x_dist = dx / cos(O - M_PI);
			if (O < M_PI + 0.02)
				x_dist = dx;
			break;
		}
		dx += 100;
		dy = dx * tan(O - M_PI);
		x = d->g_player.posx + dx;
		y = d->g_player.posy + dy;
	}
	return (x_dist);
}

int ydist_quad3(float O, int x, int y, t_cub *d)
{
	int y_dist;
	int dx;
	int dy;

	y_dist = 20000 * max(d->map_w, d->map_h);
	dy = 100 - (d->g_player.posy % 100);
	dx = dy / tan(O - M_PI);
	x = d->g_player.posx + dx;
	y = d->g_player.posy + dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y + 1) / 100][x / 100] == 1)
		{
			y_dist = dy / sin(O - M_PI);
			break;
		}
		dy += 100;
		dx = dy / tan(O - M_PI);
		x = d->g_player.posx + dx;
		y = d->g_player.posy + dy;
	}
	return (y_dist);
}

int xdist_quad4(float O, int x, int y, t_cub *d)
{
	int x_dist;
	int dx;
	int dy;

	x_dist = 20000 * max(d->map_w, d->map_h);
	dx = (d->g_player.posx % 100);
	dy = dx * tan((2 * M_PI) - O);
	x = d->g_player.posx - dx;
	y = d->g_player.posy + dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y / 100)][(x - 1) / 100] == 1)
		{
			x_dist = dy / sin((2 * M_PI) - O);
			if (O > 2 * M_PI - 0.02)
				x_dist = dx;
			break;
		}
		dx += 100;
		dy = dx * tan((2 * M_PI) - O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy + dy;
	}
	return (x_dist);
}

int ydist_quad4(float O, int x, int y, t_cub *d)
{
	int y_dist;
	int dx;
	int dy;

	y_dist = 20000 * max(d->map_w, d->map_h);
	dy = 100 - (d->g_player.posy % 100);
	dx = dy / tan((2 * M_PI) - O);
	x = d->g_player.posx - dx;
	y = d->g_player.posy + dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[(y) / 100][(x - 1) / 100] == 1)
		{
			y_dist = dy / sin((2 * M_PI) - O);
			break;
		}
		dy += 100;
		dx = dy / tan((2 * M_PI) - O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy + dy;
	}
	return (y_dist);
}

int which_wall(int dists_fov[250][2], int i)
{
	int wall;

	wall = 0x000000;
	if (dists_fov[i / 2][1] == 1)
		wall = WWALL;
	else if (dists_fov[i / 2][1] == 2)
		wall = NWALL;
	else if (dists_fov[i / 2][1] == 3)
		wall = EWALL;
	else if (dists_fov[i / 2][1] == 4)
		wall = SWALL;
	return (wall);
}

void paint_screen(int dists_fov[250][2], int i, t_cub *d)
{
	int j;
	int wall;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < (250 - (dists_fov[i / 2][0] / 2)))
		{
			//mlx_pixel_put(d->mlx, d->win, i, j, d->hex_ceil);
			put_pix(d, i, j, d->hex_ceil);
			j++;
		}
		while (j < (250 + (dists_fov[i / 2][0] / 2)) && j < 500)
		{
			wall = which_wall(dists_fov, i);
			put_pix(d, i, j, wall);
			//mlx_pixel_put(d->mlx, d->win, i, j, wall);
			j++;
		}
		while (j < 500)
		{
			//mlx_pixel_put(d->mlx, d->win, i, j, d->hex_floor);
			put_pix(d, i, j, d->hex_floor);
			j++;
		}
		i++;
	}
}

int set_dists_wall(int *x_dist, int *y_dist, int wall, float O, t_cub *d)
{
	if (O >= 0 && O < M_PI / 2)
	{
		*x_dist = xdist_quad1(O, 0, 0, d);
		*y_dist = ydist_quad1(O, 0, 0, d);
		wall = (*x_dist > *y_dist ? 4 : 3);
	}
	else if (O >= M_PI / 2 && O < M_PI)
	{
		*x_dist = xdist_quad2(O, 0, 0, d);
		*y_dist = ydist_quad2(O, 0, 0, d);
		wall = (*x_dist > *y_dist ? 4 : 1);
	}
	else if (O >= M_PI && O < 3 * M_PI / 2)
	{
		*x_dist = xdist_quad3(O, 0, 0, d);
		*y_dist = ydist_quad3(O, 0, 0, d);
		wall = (*x_dist > *y_dist ? 2 : 1);
	}
	else if (O >= 3 * M_PI / 2 && O < 2 * M_PI)
	{
		*x_dist = xdist_quad4(O, 0, 0, d);
		*y_dist = ydist_quad4(O, 0, 0, d);
		wall = (*x_dist > *y_dist ? 2 : 3);
	}
	return (wall);
}

int cast_rays(int x_dist, int y_dist, int mindist, t_cub *d)
{
	int wall; //W=1, N=2, E=3, S=4;
	int dists_fov[250][2];
	float O;
	int i;

	i = -1;
	O = d->g_player.O - 0.6;
	while (++i < 250)
	{
		O = check_limits(O);
		wall = set_dists_wall(&x_dist, &y_dist, wall, O, d);
		mindist = min(x_dist, y_dist);
		dists_fov[i][0] = 50000 / (mindist * cos(fabsf(d->g_player.O - O)));
		dists_fov[i][1] = wall;
		O += 0.0048;
	}
	paint_screen(dists_fov, 0, d);
	return (1);
}

float angle_change(int dir, float ang)
{
	if (dir == 0)
		ang -= 0.1;
	else if (dir == 1)
		ang += 0.1;
	if (ang < 0)
		ang += (2 * M_PI);
	else if (ang > 2 * M_PI)
		ang -= (2 * M_PI);
	return (ang);
}

void keys_AW(int key, t_cub *d)
{
	if (key == 0) //A
	{
		d->g_player.posx -= 10 * cos(d->g_player.O - M_PI / 2);
		d->g_player.posy -= 10 * sin(d->g_player.O - M_PI / 2);
		if (d->map[(d->g_player.posy / 100)][d->g_player.posx / 100] == 1)
		{
			d->g_player.posx += 10 * cos(d->g_player.O - M_PI / 2);
			d->g_player.posy += 10 * sin(d->g_player.O - M_PI / 2);
		}
	}
	if (key == 13) // || key == 126) //W
	{
		d->g_player.posx -= 10 * cos(d->g_player.O);
		d->g_player.posy -= 10 * sin(d->g_player.O);
		if (d->map[(d->g_player.posy / 100)][d->g_player.posx / 100] == 1)
		{
			d->g_player.posx += 10 * cos(d->g_player.O);
			d->g_player.posy += 10 * sin(d->g_player.O);
		}
	}
}

void keys_DS(int key, t_cub *d)
{
	if (key == 2) //D
	{
		d->g_player.posx -= 10 * cos(d->g_player.O + M_PI / 2);
		d->g_player.posy -= 10 * sin(d->g_player.O + M_PI / 2);
		if (d->map[(d->g_player.posy / 100)][d->g_player.posx / 100] == 1)
		{
			d->g_player.posx += 10 * cos(d->g_player.O + M_PI / 2);
			d->g_player.posy += 10 * sin(d->g_player.O + M_PI / 2);
		}
	}
	if (key == 1) // || key == 125) //S
	{
		d->g_player.posx += 10 * cos(d->g_player.O);
		d->g_player.posy += 10 * sin(d->g_player.O);
		if (d->map[(d->g_player.posy / 100)][d->g_player.posx / 100] == 1)
		{
			d->g_player.posx -= 10 * cos(d->g_player.O);
			d->g_player.posy -= 10 * sin(d->g_player.O);
		}
	}
}

// int	deal_key(int key, t_cub *d)
// {
// 	// printf("Key: %d\n", key);
// 	if (key == 53) //65307)
// 		exit(0);
// 	keys_AW(key, d);
// 	keys_DS(key, d);
// 	if (key == 123) //65361)
// 		d->g_player.O = angle_change(0, d->g_player.O);
// 	if (key == 124) //65363)
// 		d->g_player.O = angle_change(1, d->g_player.O);
// 	cast_rays(0, 0, 0, 0);
// 	return (0);
// }

void coord_to_pixel(t_cub *d)
{
	d->g_player.posx = (d->g_player.startx * 100) + 50;
	d->g_player.posy = (d->g_player.starty * 100) + 50;
}

float spawn_angle(char dir)
{
	if (dir == 'W')
	{
		printf("0.0001\n"); //for debugging
		return (0.0001);
	}
	else if (dir == 'N')
	{
		printf("%f\n", M_PI / 2);
		return (M_PI / 2);
	}
	else if (dir == 'E')
	{
		printf("%f\n", M_PI);
		return (M_PI);
	}
	else if (dir == 'S')
	{
		printf("%f\n", 3 * M_PI / 2);
		return (3 * M_PI / 2);
	}
	return (-1);
}

static int key_event(int button, void *param)
{
	t_cub *d;

	d = param;
	if (button == 65307)
	{
		clean_up(d);
		exit(0);
	}
	keys_AW(button, d);
	keys_DS(button, d);
	if (button == 65361)
		d->g_player.O = angle_change(0, d->g_player.O);
	if (button == 65363)
		d->g_player.O = angle_change(1, d->g_player.O);
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, MAX_X, MAX_Y);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
	cast_rays(0, 0, 0, 0);
	return (0);
}

void put_pix(t_cub *d, int x, int y, int color)
{
	char *dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int ft_checkarg(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i < 5)
		return (1);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' ||
		str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

static void init_data(t_cub *d)
{
	d->map = NULL;
	d->map_h = 0;
	d->map_w = 0;
	d->quant_par = 0;
	d->flag = 0;
	d->map_strings = ft_strarrnew();
	d->img = NULL;
	d->win = NULL;
	d->no.img = NULL;
	d->so.img = NULL;
	d->we.img = NULL;
	d->ea.img = NULL;
	d->g_player.startx = 0;
	d->g_player.starty = 0;
}

int main(int argc, char **argv)
{
	t_cub d;

	if (argc != 2 || ft_checkarg(argv[1]))
		ft_terror("Error\nCorrect format: ./cub3D map.cub\n");
	init_data(&d);
	init_graphics(&d);
	read_config(argv[1], &d);
	fill_map_color(&d);
	debug_print(&d);
	coord_to_pixel(&d);
	d.g_player.O = spawn_angle(d.g_player.start_dir);
	cast_rays(0, 0, 0, &d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_key_hook(d.win, &key_event, &d);
	mlx_loop(d.mlx);

	clean_up(&d);
	return (0);
}
