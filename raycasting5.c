/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanakgulati <khanakgulati@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:29 by khanakgulat       #+#    #+#             */
/*   Updated: 2021/11/22 15:39:10 by khanakgulat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cast_rays(int x_dist, int y_dist, int mindist, t_cub *d)
{
	int		wall;
	int		dists_fov[250][2];
	float	o;
	int		i;

	i = -1;
	o = d->g_player.o - 0.6;
	while (++i < 250)
	{
		o = check_limits(o);
		wall = set_dists_wall(&x_dist, &y_dist, o, d);
		mindist = min(x_dist, y_dist);
		dists_fov[i][0] = 50000 / (mindist * cos(fabsf(d->g_player.o - o)));
		dists_fov[i][1] = wall;
		o += 0.0048;
	}
	paint_screen(dists_fov, 0, d);
	return (1);
}

int	exit_hook(t_cub *d)
{
	clean_up(d);
	exit(0);
}
