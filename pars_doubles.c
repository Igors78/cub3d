/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_doubles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:42:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/16 20:44:31 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	dubl_symb(char **a, t_cub d)
{
	int	i;
	int	k;
	int	count;

	i = 1;
	k = 1;
	count = 0;
	while (i < ft_strarrlen(a) - 1)
	{
		while (k < ft_strlen(a[i]) - 1)
		{
			if (a[i][k] == 'N' || a[i][k] == 'S' || a[i][k] == 'W'
			|| a[i][k] == 'E')
				count++;
			k++;
		}
		i++;
	}
	if (count != 1)
		inv_map(d);
}

void	parse_doubles(char **a, t_cub d)
{
	int	i;
	int	k;

	i = 1;
	k = 1;
	d->map_w = ft_strlen(a[0]);
	while (i < ft_strarrlen(a) - 1)
	{
		while (k < ft_strlen(a[i]) - 1)
		{
			if (a[i][k] == '0' && (a[i - 1][k - 1] == ' '
			|| a[i - 1][k] == ' ' || a[i - 1][k + 1] == ' '
			|| a[i][k - 1] == ' ' || a[i][k + 1] == ' '
			|| a[i + 1][k - 1] == ' ' || a[i + 1][k] == ' '
			|| a[i + 1][k + 1] == ' '))
				inv_map(d);
			k++;
		}
		if (d->map_w < ft_strlen(a[i]))
			d->map_w = ft_strlen(a[i]);
		i++;
	}
	dubl_symb(a, d);
}
