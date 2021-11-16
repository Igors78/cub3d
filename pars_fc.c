/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:09:29 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/16 17:12:48 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_floor(char **arr, t_cub d)
{
	if (d->f_color || ft_strarrlen(arr) > 6)
	{
		ft_split_free(arr);
		inv_color(d);
	}
	d->quant_par++;
	

}
