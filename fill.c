/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:05:51 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/18 08:34:47 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	prefill(t_cub *d)
{
	int	i;
	int	k;

	i = 0;
	while (i < d->map_h)
	{
		k = 0;
		while (k < d->map_w)
		{
			d->map[i][k] = 2;
			k++;
		}
		i++;
	}
}

void	fill_map_color(t_cub *d)
{
	int	i;

	i = 0;
	d->hex_floor = (d->f_color[0] << 16 | d->f_color[1] << 8 | d->f_color[2]);
	d->hex_ceil = (d->c_color[0] << 16 | d->c_color[1] << 8 | d->c_color[2]);
	d->map = (int **)malloc(sizeof(int *) * d->map_h);
	while (i < d->map_h)
	{
		d->map[i] = (int *)malloc(sizeof(int) * d->map_w);
		i++;
	}
	prefill(d);
}
