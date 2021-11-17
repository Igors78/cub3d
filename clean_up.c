/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:27:03 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 15:52:57 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	inv_map(t_cub *d)
{
	clean_up(d);
	ft_terror("Error\nNot valid map");
}

void	inv_color(t_cub *d)
{
	clean_up(d);
	ft_terror("Error\nNot valid color specification");
}

void	clean_up(t_cub *d)
{
	int	i;

	i = 0;
	while (d->map_strings[i])
	{
		free(d->map_strings[i]);
		i++;
	}
	free(d->map_strings);
	mlx_destroy_image(d->mlx, d->no.img);
	mlx_destroy_image(d->mlx, d->so.img);
	mlx_destroy_image(d->mlx, d->ea.img);
	mlx_destroy_image(d->mlx, d->we.img);
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
}
