/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:29:24 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 15:18:51 by ioleinik         ###   ########.fr       */
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
}
