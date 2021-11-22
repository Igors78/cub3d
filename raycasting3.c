/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:08:06 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 14:26:12 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

float	check_limits(float o)
{
	if (o < 0)
		o += (2 * M_PI);
	else if (o > (2 * M_PI))
		o -= (2 * M_PI);
	return (o);
}

float	angle_change(int dir, float ang)
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

void	coord_to_pixel(t_cub *d)
{
	d->g_player.posx = (d->g_player.startx * 100) + 50;
	d->g_player.posy = (d->g_player.starty * 100) + 50;
}
