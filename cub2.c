#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define CEIL 0x59bfff
#define FLOOR 0x003300
#define WWALL 0xff0000
#define NWALL 0x00ff00
#define EWALL 0x0000ff
#define SWALL 0xffff00

int grid[8][8] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},	
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct s_player
{
	int posx;
	int posy;
	float O;
	int startx;
	int starty;
	char start_dir;
} t_player;

t_player *g_player;
void *mlx_ptr;
void *win_ptr;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int min(int a, int b)
{
	return (a > b ? b : a);
}

float check_limits(float O)
{
	if (O < -0.012)
		O += (2 * M_PI);
	else if (O > (2 * M_PI) - 0.012)
		O -= (2 * M_PI);
	else if (O > 0 && O < 0.012)
		O = 0.012;
	else if (O < (2 * M_PI) && O > (2 * M_PI) - 0.012)
		O = (2 * M_PI) - 0.012;
	
	// if (O > (M_PI / 2) - 0.012 && O < (M_PI / 2))
	// 	O = (M_PI / 2) - 0.012;
	// else if (O > (M_PI / 2) && O < (M_PI / 2) + 0.012)
	// 	O = (M_PI / 2) + 0.012;
	
	if (O > M_PI - 0.012 && O < M_PI)
		O = M_PI - 0.012;
	else if (O > M_PI && O < M_PI + 0.012)
		O = M_PI + 0.012;

	if (O > (3 * M_PI / 2) - 0.012 && O < (3 * M_PI / 2))
		O = (3 * M_PI / 2) - 0.012;
	else if (O > (3 * M_PI / 2) && O < (3 * M_PI / 2) + 0.012)
		O = (3 * M_PI / 2) + 0.012;
	
	return (O);
}

void	cast_rays(int grid_w, int grid_h)
{
	int x_dist;
	int y_dist;
	int mindist;
	int x;
	int y;
	int dx;
	int dy;
	int wall; //W=1, N=2, E=3, S=4;
	int dists_fov[100][2];
	int i;
	int j;
	float O;

	i = -1;
	O = g_player->O - 0.6;
	while (++i < 100)
	{
		O = check_limits(O);
		//this part sets the values for x_dist and y_dist (then, whichever is smaller is taken as ray dist; direction facing is set accordingly; then wall length is calculated)
		x_dist = 200 * max(grid_w, grid_h);
		y_dist = 200 * max(grid_w, grid_h);
		if (O >= 0 && O < M_PI / 2)
		{
			//finding x_dist
			dx = (g_player->posx % 100); //x goes to nearest line on left
			dy = dx * tan(O); //diff in y depends on angle
			x = g_player->posx - dx; //x and y are the positions of the ray when intersecting a vertical line
			y = g_player->posy - dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[((y - 1) / 100)][(x - 1) / 100] == 1) //i-j coordinates of the block that the ray is intersecting (on the grid) :
				{
					x_dist = dx / cos(O); //length of the ray
					break ;
				}
				dx += 100; //if grid value of block is 0 (empty space), keep going to the next vertical line until intersection with grid value 1 found
				dy = dx * tan(O);
				x = g_player->posx - dx;
				y = g_player->posy - dy;
			}
			//finding y_dist
			dy = g_player->posy % 100;
			dx = dy / tan(O);
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				x = g_player->posx - dx;
				y = g_player->posy - dy;
				if (grid[(y - 1) / 100][((x - 1) / 100)] == 1)
				{
					y_dist = dy / sin(O);
					break ;
				}
				dy += 100;
				dx = dy / tan(O);
			}
			mindist = min(x_dist, y_dist);
			wall = (x_dist > y_dist ? 4 : 3);
		}
		else if (O >= M_PI / 2 && O < M_PI)
		{
			dx = 100 - (g_player->posx % 100);
			dy = dx * tan(M_PI - O);
			x = g_player->posx + dx;
			y = g_player->posy - dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[((y-1) / 100)][(x + 1) / 100] == 1)
				{
					x_dist = dy / sin(M_PI - O);
					break ;
				}
				dx += 100;
				dy = dx * tan(M_PI - O);
				x = g_player->posx + dx;
				y = g_player->posy - dy;
			}
			dy = g_player->posy % 100;
			dx = dy / tan(M_PI - O);
			x = g_player->posx + dx;
			y = g_player->posy - dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[(y - 1) / 100][x / 100] == 1)
				{
					y_dist = dy / sin(M_PI - O);
					break ;
				}
				dy += 100;
				dx = dy / tan(M_PI - O);
				x = g_player->posx + dx;
				y = g_player->posy - dy;
			}
			mindist = min(x_dist, y_dist);
			wall = (x_dist > y_dist ? 4 : 1);
		}
		else if (O >= M_PI && O < 3 * M_PI / 2)
		{
			dx = 100 - (g_player->posx % 100);
			dy = dx * tan(O - M_PI);
			x = g_player->posx + dx;
			y = g_player->posy + dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[(y / 100)][(x + 1) / 100] == 1)
				{
					x_dist = dx / cos(O - M_PI);
					break ;
				}
				dx += 100;
				dy = dx * tan(O - M_PI);
				x = g_player->posx + dx;
				y = g_player->posy + dy;
			}
			dy = 100 - (g_player->posy % 100);
			dx = dy / tan(O - M_PI);
			x = g_player->posx + dx;
			y = g_player->posy + dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[(y + 1) / 100][x / 100] == 1)
				{
					y_dist = dy / sin(O - M_PI);
					break ;
				}
				dy += 100;
				dx = dy / tan(O - M_PI);
				x = g_player->posx + dx;
				y = g_player->posy + dy;
			}
			mindist = min(x_dist, y_dist);
			wall = (x_dist > y_dist ? 2 : 1);
		}
		else if (O >= 3 * M_PI / 2 && O < 2 * M_PI)
		{
			dx = (g_player->posx % 100);
			dy = dx * tan((2 * M_PI) - O);
			x = g_player->posx - dx;
			y = g_player->posy + dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[(y / 100)][(x - 1) / 100] == 1)
				{
					x_dist = dy / sin((2 * M_PI) - O);
					break ;
				}
				dx += 100;
				dy = dx * tan((2 * M_PI) - O);
				x = g_player->posx - dx;
				y = g_player->posy + dy;
			}
			dy = 100 - (g_player->posy % 100);
			dx = dy / tan((2 * M_PI) - O);
			x = g_player->posx - dx;
			y = g_player->posy + dy;
			while (x > 0 && x < (grid_w * 100) && y > 0 && y < (grid_h * 100))
			{
				if (grid[(y) / 100][(x-1) / 100] == 1)
				{
					y_dist = dy / sin((2 * M_PI) - O);
					break ;
				}
				dy += 100;
				dx = dy / tan((2 * M_PI) - O);
				x = g_player->posx - dx;
				y = g_player->posy + dy;
			}
			mindist = min(x_dist, y_dist);
			wall = (x_dist > y_dist ? 2 : 3);
		}
		dists_fov[i][0] = 50000 / (mindist * cos(fabsf(g_player->O - O)));
		dists_fov[i][1] = wall;
		O += 0.012;
	}
	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < (250 - (dists_fov[i / 5][0] / 2)))
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, CEIL);
			j++;
		}
		while (j < (250 + (dists_fov[i / 5][0] / 2)) && j < 500)
		{
			if (dists_fov[i / 5][1] == 1)
				wall = WWALL;
			else if (dists_fov[i / 5][1] == 2)
				wall = NWALL;
			else if (dists_fov[i / 5][1] == 3)
				wall = EWALL;
			else if (dists_fov[i / 5][1] == 4)
				wall = SWALL;
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, wall);
			j++;
		}
		while (j < 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, FLOOR);
			j++;
		}
		i++;
	}
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

int	deal_key(int key, t_player *player)
{
	if (key == 53)
		exit(0);
	if (key == 0) //A
	{
		player->posx -= 10 * cos(player->O - M_PI / 2);
		player->posy -= 10 * sin(player->O - M_PI / 2);
	}
	if (key == 13) //W
	{
		player->posx -= 10 * cos(player->O);
		player->posy -= 10 * sin(player->O);
	}
	if (key == 2) //D
	{
		player->posx -= 10 * cos(player->O + M_PI / 2);
		player->posy -= 10 * sin(player->O + M_PI / 2);
	}
	if (key == 1) //S
	{
		player->posx += 10 * cos(player->O);
		player->posy += 10 * sin(player->O);
	}
	if (key == 123)
		player->O = angle_change(0, player->O);
	if (key == 124)
		player->O = angle_change(1, player->O);
	cast_rays(8, 8);
	return (0);
}

void coord_to_pixel(void)
{
	g_player->posx = (g_player->startx * 100) + 50;
	g_player->posy = (g_player->starty * 100) + 50;
}

float spawn_angle(char dir)
{
	if (dir == 'W')
		return (0.0001);
	else if (dir == 'N')
		return (M_PI / 2);
	else if (dir == 'E')
		return (M_PI);
	else if (dir == 'S')
		return (3 * M_PI);
	return (-1);
}

int main(void)
{
	g_player = malloc(sizeof(t_player));
	// **** call player_init function to feed the following info into g_player, to be read from .cub file **** //
	g_player->startx = 4;
	g_player->starty = 4;
	g_player->start_dir = 'W';
	coord_to_pixel();
	g_player->O = spawn_angle(g_player->start_dir);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	cast_rays(8, 8);
	mlx_key_hook(win_ptr, deal_key, g_player);
    mlx_loop(mlx_ptr);
	free(g_player);
}
