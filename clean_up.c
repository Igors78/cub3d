/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:27:03 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/22 12:24:03 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_color(char **arr, char **col, t_cub *d)
{
	ft_split_free(arr);
	ft_split_free(col);
	inv_color(d);
}

void	inv_map(t_cub *d)
{
	clean_up(d);
	ft_terror("Error\nNot valid map\n");
}

void	inv_color(t_cub *d)
{
	clean_up(d);
	ft_terror("Error\nNot valid color specification\n");
}

static void	cl_upgraph(t_cub *d)
{
	if (d->no.img)
		mlx_destroy_image(d->mlx, d->no.img);
	if (d->so.img)
		mlx_destroy_image(d->mlx, d->so.img);
	if (d->ea.img)
		mlx_destroy_image(d->mlx, d->ea.img);
	if (d->we.img)
		mlx_destroy_image(d->mlx, d->we.img);
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	free(d->mlx);
}

void	clean_up(t_cub *d)
{
	int	i;

	i = 0;
	if (d->map_strings)
	{
		while (d->map_strings[i])
			free(d->map_strings[i++]);
		free(d->map_strings);
	}
	i = 0;
	if (d->map)
	{
		while (i < d->map_h)
			free(d->map[i++]);
		free(d->map);
	}
	cl_upgraph(d);
}
