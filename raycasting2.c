/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:07:08 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 10:34:42 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int which_wall(int dists_fov[250][2], int i, t_cub *d)
{
	int wall;

	wall = 0x000000;
	if (dists_fov[i / 2][1] == 1)
	{
		wall = (*(int *)(d->no.addr + ((d->no.img_h +
										(d->no.img_w * 64)) *
									   (d->no.bits_per_pixel / 8))));
	}
	else if (dists_fov[i / 2][1] == 2)
	{
		wall = (*(int *)(d->so.addr + ((d->so.img_h +
										(d->so.img_w * 64)) *
									   (d->so.bits_per_pixel / 8))));
	}
	else if (dists_fov[i / 2][1] == 3)
	{
		wall = (*(int *)(d->we.addr + ((d->we.img_h +
										(d->we.img_w * 64)) *
									   (d->we.bits_per_pixel / 8))));
	}
	else if (dists_fov[i / 2][1] == 4)
	{
		wall = (*(int *)(d->ea.addr + ((d->ea.img_h +
										(d->ea.img_w * 64)) *
									   (d->ea.bits_per_pixel / 8))));
	}
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
			put_pix(d, i, j, d->hex_ceil);
			j++;
		}
		while (j < (250 + (dists_fov[i / 2][0] / 2)) && j < 500)
		{
			wall = which_wall(dists_fov, i, d);
			put_pix(d, i, j, wall);
			j++;
		}
		while (j < 500)
		{
			put_pix(d, i, j, d->hex_floor);
			j++;
		}
		i++;
	}
}
