/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:29:24 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/18 08:42:43 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	debug_print(t_cub *d)
{
	int	i;
	int	k;

	i = 0;
	while (d->map_strings[i])
		printf("%s\n", d->map_strings[i++]);
	printf("%X\n", d->hex_ceil);
	printf("%X\n", d->hex_floor);
	i = 0;
	while (i < d->map_h)
	{
		k = 0;
		while (k < d->map_w)
			printf("%d", d->map[i][k++]);
		printf("\n");
		i++;
	}
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
}
