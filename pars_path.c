/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:30 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/15 16:29:05 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	parse_path(char **str, t_cub d)
{
	if (ft_strarrlen(str) == 2)
	{
		d->quant_par++;
		if (ft_strcmp(str[0], "NO") == 0 && ft_strlen(str[0] == 2))
			nord_text(str[1], d);
		else if (ft_strcmp(str[0], "SO") == 0 && ft_strlen(str[0] == 2))
			south_text(str[1], d);
		else if (ft_strcmp(str[0], "WE") == 0 && ft_strlen(str[0] == 2))
			west_text(str[1], d);
		else if (ft_strcmp(str[0], "EA") == 0 && ft_strlen(str[0] == 2))
			east_text(str[1], d);
	}
	else
	{
		ft_split_free(str);
		free(d);
		ft_terror("Error\nTexture parameter fail");
	}
}
