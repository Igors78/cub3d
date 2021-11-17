/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_doubles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:42:08 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 16:41:33 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	open_map(char **a, int i, int k)
{
	if (a[i][k] == '0' && (a[i][k - 1] == ' ' || a[i][k + 1] == ' '))
		return (1);
	if (a[i][k] == '0' && (k > (int)ft_strlen(a[i - 1])
	|| k > (int)ft_strlen(a[i + 1])))
		return (1);
	if (k + 1 < (int)ft_strlen(a[i - 1]))
	{
		if (a[i][k] == '0' && (a[i - 1][k - 1] == ' '
			|| a[i - 1][k] == ' ' || a[i - 1][k + 1] == ' '))
			return (1);
	}
	if (k + 1 < (int)ft_strlen(a[i + 1]))
	{
		if (a[i][k] == '0' && (a[i + 1][k - 1] == ' ' || a[i + 1][k] == ' '
			|| a[i + 1][k + 1] == ' '))
			return (1);
	}
	return (0);
}

static void	dubl_symb(char **a, t_cub *d)
{
	size_t	i;
	size_t	k;
	int		count;

	i = 1;
	k = 1;
	count = 0;
	while (i < (size_t)ft_strarrlen(a) - 1)
	{
		k = 1;
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

void	parse_doubles(char **a, t_cub *d)
{
	size_t	i;
	size_t	k;

	i = 1;
	k = 1;
	d->map_w = ft_strlen(a[0]);
	while (i < (size_t)ft_strarrlen(a) - 1)
	{
		k = 1;
		while (k < ft_strlen(a[i]) - 1)
		{
			if (open_map(a, i, k))
				inv_map(d);
			k++;
		}
		if (d->map_w < (int)ft_strlen(a[i]))
			d->map_w = (int)ft_strlen(a[i]);
		i++;
	}
	dubl_symb(a, d);
}
