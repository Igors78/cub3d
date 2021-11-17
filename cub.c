/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 11:54:01 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// < d > stands for data table stored in s_cub structure

static int	ft_checkarg(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i < 5)
		return (1);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || \
		str[i - 3] != 'c' || str[i - 4] != '.')
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
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, MAX_X, MAX_Y, "cub");
	d->img = mlx_new_image(d->mlx, MAX_X, MAX_Y);
	d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel), &(d->line_length),
			&(d->endian));
	d->no.img = NULL;
	d->so.img = NULL;
	d->we.img = NULL;
	d->ea.img = NULL;
}

// static int	key_event(int button, void *param)
// {
// 	t_cub	d;

// 	d = param;
// 	if (button == 65307)
// 		clean_up(d);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_cub	d;

	if (argc != 2 || ft_checkarg(argv[1]))
		ft_terror("Error\nCorrect format: ./cub3D map.cub\n");
	init_data(&d);
	read_config(argv[1], &d);
	debug_print(&d);
	// mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	// mlx_key_hook(d->win, &key_event, d);
	// mlx_loop(d->mlx);
	return (0);
}
