/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:09:29 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 11:24:25 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_colrange(char **arr, char *s, t_cub d)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			ft_split_free(arr);
			inv_color(d);
		}
		i++;
	}
}

static void	fill_floorcolor(char **arr, char *s, t_cub d)
{
	static int	count;
	int			value;

	value = 0;
	if (s[0] == '0' && s[1] == '\0')
	{
		d->f_color[count++] = 0;
		return ;
	}
	value = ft_atoi(s);
	if (value < 1 || value > 255 || count > 3)
	{
		ft_split_free(arr);
		inv_color(d);
	}
	d->f_color[count++] = value;
}

static void	fill_ceilcolor(char **arr, char *s, t_cub d)
{
	static int	count;
	int			value;

	value = 0;
	if (s[0] == '0' && s[1] == '\0')
	{
		d->c_color[count++] = 0;
		return ;
	}
	value = ft_atoi(s);
	if (value < 1 || value > 255 || count > 3)
	{
		ft_split_free(arr);
		inv_color(d);
	}
	d->c_color[count++] = value;
}

void	parse_floor(char **arr, t_cub d)
{
	int		i;
	char	**col;

	i = 1;
	if (d->f_color || ft_strarrlen(arr) > 6)
	{
		ft_split_free(arr);
		inv_color(d);
	}
	d->quant_par++;
	while (i < ft_strarrlen(arr))
	{
		if (arr[i][ft_strlen(arr[i]) - 1] == ',')
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
		if (arr[i][0])
		{
			check_colrange(arr, arr[i], d);
			fill_floorcolor(arr, arr[i], d);
		}
		i++;
	}
}

void	parse_ceil(char **arr, t_cub d)
{
	int		i;
	char	**col;

	i = 1;
	if (d->f_color || ft_strarrlen(arr) > 6)
	{
		ft_split_free(arr);
		inv_color(d);
	}
	d->quant_par++;
	while (i < ft_strarrlen(arr))
	{
		if (arr[i][ft_strlen(arr[i]) - 1] == ',')
			arr[i][ft_strlen(arr[i]) - 1] = '\0';
		if (arr[i][0])
		{
			check_colrange(arr, arr[i], d);
			fill_ceilcolor(arr, arr[i], d);
		}
		i++;
	}
}
