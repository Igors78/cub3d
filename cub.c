/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/23 12:59:02 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define WWALL 0xff0000
#define NWALL 0x00ff00
#define EWALL 0x0000ff
#define SWALL 0xffff00

static int	key_event(int button, void *param)
{
	t_cub	*d;

	d = param;
	if (button == 65307 || button == 53)
	{
		clean_up(d);
		exit(0);
	}
	keys_aw(button, d, 0, 0);
	keys_ds(button, d, 0, 0);
	if (button == 65361 || button == 123)
		d->g_player.o = angle_change(0, d->g_player.o);
	if (button == 65363 || button == 124)
		d->g_player.o = angle_change(1, d->g_player.o);
	render(d);
	return (0);
}

void	put_pix(t_cub *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	ft_checkarg(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (1);
	if (str[i - 1] != 'b' || str[i - 2] != 'u'
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	return (0);
}

static void	init_data(t_cub *d)
{
	d->map = NULL;
	d->map_h = 0;
	d->map_w = 0;
	d->quant_par = 0;
	d->flag = 0;
	d->map_strings = ft_strarrnew();
	d->img = NULL;
	d->win = NULL;
	d->g_player.startx = 0;
	d->g_player.starty = 0;
	d->f_color[0] = 0;
	d->f_color[1] = 0;
	d->f_color[2] = 0;
	d->c_color[0] = 0;
	d->c_color[1] = 0;
	d->c_color[2] = 0;
}

int	main(int argc, char **argv)
{
	t_cub	d;

	if (argc != 2 || ft_checkarg(argv[1]))
		ft_terror("Error\nCorrect format: ./cub3D map.cub\n");
	init_data(&d);
	init_graphics(&d);
	read_config(argv[1], &d);
	fill_map_color(&d);
	coord_to_pixel(&d);
	d.g_player.o = spawn_angle(d.g_player.start_dir);
	cast_rays(0, 0, 0, &d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_do_key_autorepeatoff(d.mlx);
	mlx_hook(d.win, 2, 1L << 0, &key_event, &d);
	mlx_hook(d.win, 17, 0, &exit_hook, &d);
	mlx_loop(d.mlx);
	clean_up(&d);
	return (0);
}
