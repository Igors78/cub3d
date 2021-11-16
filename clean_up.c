/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:27:03 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/16 10:29:00 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	inv_map(t_cub d)
{
	clean_up(d);
	ft_terror("Error\nNot valid map");
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
