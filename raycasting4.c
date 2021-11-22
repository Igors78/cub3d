/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:09:22 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 10:34:21 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	int wall;
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



void keys_AW(int key, t_cub *d, int x, int y)
{
	if (key == 115 || key == 0)
	{
        x = d->g_player.posx - 10 * cos(d->g_player.O - M_PI / 2);
        y = d->g_player.posy - 10 * sin(d->g_player.O - M_PI / 2);
        if (!(y / 100 <= 0 || y / 100 >= d->map_h - 1
			|| x / 100 <= 0 || x / 100 >= d->map_w - 1
            || d->map[y / 100][x / 100] == 1))
		{
			d->g_player.posx -= 10 * cos(d->g_player.O - M_PI / 2);
		    d->g_player.posy -= 10 * sin(d->g_player.O - M_PI / 2);
		}
	}
	if (key == 119 || key == 13)
	{
        x = d->g_player.posx - 10 * cos(d->g_player.O);
        y = d->g_player.posy - 10 * sin(d->g_player.O);
        if (!(y / 100 <= 0 || y / 100 >= d->map_h - 1
			|| x / 100 <= 0 || x / 100 >= d->map_w - 1
            || d->map[y / 100][x / 100] == 1))
		{
			d->g_player.posx -= 10 * cos(d->g_player.O);
		    d->g_player.posy -= 10 * sin(d->g_player.O);
		}
	}
}

void keys_DS(int key, t_cub *d, int x, int y)
{
	if (key == 100 || key == 2)
	{
        x = d->g_player.posx - 10 * cos(d->g_player.O + M_PI / 2);
        y = d->g_player.posy - 10 * sin(d->g_player.O + M_PI / 2);
        if (!(y / 100 <= 0 || y / 100 >= d->map_h - 1
			|| x / 100 <= 0 || x / 100 >= d->map_w - 1
            || d->map[y / 100][x / 100] == 1))
		{
			d->g_player.posx -= 10 * cos(d->g_player.O + M_PI / 2);
		    d->g_player.posy -= 10 * sin(d->g_player.O + M_PI / 2);
		}
    }
	if (key == 97 || key == 1)
	{
        x = d->g_player.posx + 10 * cos(d->g_player.O);
        y = d->g_player.posy + 10 * sin(d->g_player.O);
        if (!(y / 100 <= 0 || y / 100 >= d->map_h - 1
			|| x / 100 <= 0 || x / 100 >= d->map_w - 1
            || d->map[y / 100][x / 100] == 1))
		{
			d->g_player.posx += 10 * cos(d->g_player.O);
		    d->g_player.posy += 10 * sin(d->g_player.O);
		}
	}
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
		return (3 * M_PI / 2);
	return (-1);
}
