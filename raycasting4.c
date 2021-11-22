/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:09:22 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 11:09:45 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	set_dists_wall2(int *x_dist, int *y_dist, float O, t_cub *d)
{
	int	wall;

	wall = 0;
	if (O >= M_PI && O < 3 * M_PI / 2)
	{
		*x_dist = xdist_quad3(O, 0, 0, d);
		*y_dist = ydist_quad3(O, 0, 0, d);
		if (*x_dist > *y_dist)
			wall = 2;
		else
			wall = 1;
	}
	else if (O >= 3 * M_PI / 2 && O < 2 * M_PI)
	{
		*x_dist = xdist_quad4(O, 0, 0, d);
		*y_dist = ydist_quad4(O, 0, 0, d);
		if (*x_dist > *y_dist)
			wall = 2;
		else
			wall = 3;
	}
	return (wall);
}

int	set_dists_wall(int *x_dist, int *y_dist, float O, t_cub *d)
{
	int	wall;

	wall = 0;
	if (O >= 0 && O < M_PI / 2)
	{
		*x_dist = xdist_quad1(O, 0, 0, d);
		*y_dist = ydist_quad1(O, 0, 0, d);
		if (*x_dist > *y_dist)
			wall = 4;
		else
			wall = 3;
	}
	else if (O >= M_PI / 2 && O < M_PI)
	{
		*x_dist = xdist_quad2(O, 0, 0, d);
		*y_dist = ydist_quad2(O, 0, 0, d);
		if (*x_dist > *y_dist)
			wall = 4;
		else
			wall = 1;
	}
	else
		wall = set_dists_wall2(x_dist, y_dist, O, d);
	return (wall);
}

void	keys_AW(int key, t_cub *d, int x, int y)
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

void	keys_DS(int key, t_cub *d, int x, int y)
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

float	spawn_angle(char dir)
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
