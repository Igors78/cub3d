/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:09:29 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/23 15:11:36 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_colrange(char **arr, char *s, t_cub *d)
{
	int		i;
	int		k;
	char	**col;

	col = ft_split(s, ',');
	i = 0;
	k = 0;
	while (col[i])
	{
		k = 0;
		while (col[i][k])
		{
			if (!ft_isdigit(col[i][k]))
			{
				ft_split_free(arr);
				ft_split_free(col);
				inv_color(d);
			}
			k++;
		}
		i++;
	}
	ft_split_free(col);
}

static void	fill_floorcolor(char **arr, char *s, t_cub *d)
{
	static int	count;
	int			value;
	int			i;
	char		**col;

	col = ft_split(s, ',');
	i = 0;
	value = 0;
	while (col[i])
	{
		if (col[i][0] && col[i][0] == '0' && !col[i][1])
		{
			d->f_color[count++] = 0;
			i++;
			continue ;
		}
		if (col[i][0])
			value = ft_atoi(col[i]);
		if (value < 1 || value > 255 || count > 3)
			exit_color(arr, col, d);
		d->f_color[count++] = value;
		i++;
	}
	ft_split_free(col);
}

static void	fill_ceilcolor(char **arr, char *s, t_cub *d)
{
	static int	count;
	int			value;
	int			i;
	char		**col;

	col = ft_split(s, ',');
	i = 0;
	value = 0;
	count = 0;
	while (col[i])
	{
		if (col[i][0] && col[i][0] == '0' && !col[i][1])
		{
			d->c_color[count++] = 0;
			i++;
			continue ;
		}
		if (col[i][0])
			value = ft_atoi(col[i]);
		if (value < 1 || value > 255 || count > 3)
			exit_color(arr, col, d);
		d->c_color[count++] = value;
		i++;
	}
	ft_split_free(col);
}

void	parse_floor(char **arr, t_cub *d)
{
	int		i;

	i = 1;
	if (ft_strarrlen(arr) > 6)
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

void	parse_ceil(char **arr, t_cub *d)
{
	int		i;

	i = 1;
	if (ft_strarrlen(arr) > 6)
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
