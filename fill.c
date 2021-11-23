/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:05:51 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/23 15:29:33 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fill_field(t_cub *d)
{
	int	i;
	int	k;

	i = 0;
	while (i < d->map_h)
	{
		k = 0;
		while (k < (int)ft_strlen(d->map_strings[i]))
		{
			if (d->map_strings[i][k] == '0')
				d->map[i][k] = 0;
			if (d->map_strings[i][k] == '1')
				d->map[i][k] = 1;
			if (d->map_strings[i][k] == 'N' || d->map_strings[i][k] == 'S'
			|| d->map_strings[i][k] == 'W' || d->map_strings[i][k] == 'E')
			{
				d->g_player.start_dir = d->map_strings[i][k];
				d->map[i][k] = 0;
				d->g_player.starty = i;
				d->g_player.startx = k;
			}
			k++;
		}
		i++;
	}
}

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
		d->map[i] = (int *)malloc(sizeof(int) * (d->map_w + 1));
		i++;
	}
	prefill(d);
	fill_field(d);
}
