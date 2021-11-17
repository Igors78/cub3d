/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:29:24 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 18:37:12 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	debug_print(t_cub *d)
{
	int	i;

	i = 0;
	while (d->map_strings[i])
	{
		printf("%s\n", d->map_strings[i]);
		i++;
	}
	printf("%d\n", d->f_color[0]);
	printf("%d\n", d->f_color[1]);
	printf("%d\n", d->f_color[2]);
	printf("%d\n", d->c_color[0]);
	printf("%d\n", d->c_color[1]);
	printf("%d\n", d->c_color[2]);
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
