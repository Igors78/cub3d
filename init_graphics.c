/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:06:15 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/22 12:20:07 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_tex(t_cub *d)
{
	d->ea.img = NULL;
	d->ea.addr = NULL;
	d->ea.bits_per_pixel = 0;
	d->ea.img_w = 0;
	d->ea.img_h = 0;
	d->ea.line_length = 0;
	d->ea.endian = 0;
	d->we.img = NULL;
	d->we.addr = NULL;
	d->we.bits_per_pixel = 0;
	d->we.img_w = 0;
	d->we.img_h = 0;
	d->we.line_length = 0;
	d->we.endian = 0;
}

void	init_graphics(t_cub *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, MAX_X, MAX_Y, "cub");
	d->img = mlx_new_image(d->mlx, MAX_X, MAX_Y);
	d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel), &(d->line_length),
			&(d->endian));
	d->no.img = NULL;
	d->no.addr = NULL;
	d->no.bits_per_pixel = 0;
	d->no.img_w = 0;
	d->no.img_h = 0;
	d->no.line_length = 0;
	d->no.endian = 0;
	d->so.img = NULL;
	d->so.addr = NULL;
	d->so.bits_per_pixel = 0;
	d->so.img_w = 0;
	d->so.img_h = 0;
	d->so.line_length = 0;
	d->so.endian = 0;
	init_tex(d);
}
