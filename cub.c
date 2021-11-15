/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/15 20:40:39 by ioleinik         ###   ########.fr       */
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

void	clean_up(t_cub d)
{
	int	i;

	i = 0;
	// while (i < d->h)
	// {
	// 	free(d->a[i]);
	// 	free(d->c[i]);
	// 	i++;
	// }
	// free(d->a);
	// free(d->c);
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d);
}

static void	init_data(t_cub d)
{
	d->f_color[3] = NULL;
	d->c_color[3] = NULL;
	d->map = NULL;
	d->quant_par = 0;
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

static int	key_event(int button, void *param)
{
	t_cub	d;

	d = param;
	if (button == 65307)
		clean_up(d);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	d;

	if (argc != 2 || ft_checkarg(argv[1]))
		ft_terror("Error\nCorrect format: ./cub3D map.cub\n");
	d = (t_cub)malloc(sizeof(struct s_cub));
	if (!d)
		ft_terror("Error\nMemory allocation failed\n");
	init_data(d);
	read_config(argv[1], d);
	plot(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_key_hook(d->win, &key_event, d);
	mlx_loop(d->mlx);
	return (0);
}
