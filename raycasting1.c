/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:17 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 11:10:30 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	xdist_quad1(float O, int x, int y, t_cub *d)
{
	int	x_dist;
	int	dx;
	int	dy;

	x_dist = 20000 * max(d->map_w, d->map_h);
	dx = (d->g_player.posx % 100);
	dy = dx * tan(O);
	x = d->g_player.posx - dx;
	y = d->g_player.posy - dy;
	while (x > 0 && x < (d->map_w * 100) && y > 0 && y < (d->map_h * 100))
	{
		if (d->map[((y - 1) / 100)][(x - 1) / 100] == 1)
		{
			x_dist = dx / cos(O);
			if (O < 0.02)
				x_dist = dx;
			break ;
		}
		dx += 100;
		dy = dx * tan(O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy - dy;
	}
	return (x_dist);
}

int	ydist_quad1(float O, int x, int y, t_cub *d)
{
	int	y_dist;
	int	dx;
	int	dy;

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
			break ;
		}
		dy += 100;
		dx = dy / tan(O);
		x = d->g_player.posx - dx;
		y = d->g_player.posy - dy;
	}
	return (y_dist);
}

int	xdist_quad2(float O, int x, int y, t_cub *d)
{
	int	x_dist;
	int	dx;
	int	dy;

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
			break ;
		}
		dx += 100;
		dy = dx * tan(M_PI - O);
		x = d->g_player.posx + dx;
		y = d->g_player.posy - dy;
	}
	return (x_dist);
}

int	ydist_quad2(float O, int x, int y, t_cub *d)
{
	int	y_dist;
	int	dx;
	int	dy;

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
			break ;
		}
		dy += 100;
		dx = dy / tan(M_PI - O);
		x = d->g_player.posx + dx;
		y = d->g_player.posy - dy;
	}
	return (y_dist);
}

int	xdist_quad3(float O, int x, int y, t_cub *d)
{
	int	x_dist;
	int	dx;
	int	dy;

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
			break ;
		}
		dx += 100;
		dy = dx * tan(O - M_PI);
		x = d->g_player.posx + dx;
		y = d->g_player.posy + dy;
	}
	return (x_dist);
}
