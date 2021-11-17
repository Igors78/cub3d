/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:30 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 18:05:39 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	nord_tex(char **str, char *s, t_cub *d)
{
	if (d->no.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nDouble inclusion of texture\n");
	}
	d->no.img = mlx_xpm_file_to_image(d->mlx, s, &d->no.img_w, &d->no.img_h);
	if (NULL == d->no.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nInvalid texture\n");
	}
	d->no.addr = mlx_get_data_addr(d->no.img, &d->no.bits_per_pixel,
			&d->no.line_length, &d->no.endian);
}

static void	south_tex(char **str, char *s, t_cub *d)
{
	if (d->so.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nDouble inclusion of texture\n");
	}
	d->so.img = mlx_xpm_file_to_image(d->mlx, s, &d->so.img_w, &d->so.img_h);
	if (NULL == d->so.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nInvalid texture\n");
	}
	d->so.addr = mlx_get_data_addr(d->so.img, &d->so.bits_per_pixel,
			&d->so.line_length, &d->so.endian);
}

static void	west_tex(char **str, char *s, t_cub *d)
{
	if (d->we.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nDouble inclusion of texture\n");
	}
	d->we.img = mlx_xpm_file_to_image(d->mlx, s, &d->we.img_w, &d->we.img_h);
	if (NULL == d->we.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nInvalid texture\n");
	}
	d->we.addr = mlx_get_data_addr(d->we.img, &d->we.bits_per_pixel,
			&d->we.line_length, &d->we.endian);
}

static void	east_tex(char **str, char *s, t_cub *d)
{
	if (d->ea.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nDouble inclusion of texture\n");
	}
	d->ea.img = mlx_xpm_file_to_image(d->mlx, s, &d->ea.img_w, &d->ea.img_h);
	if (NULL == d->ea.img)
	{
		clean_up(d);
		ft_split_free(str);
		ft_terror("Error\nInvalid texture\n");
	}
	d->ea.addr = mlx_get_data_addr(d->ea.img, &d->ea.bits_per_pixel,
			&d->ea.line_length, &d->ea.endian);
}

void	parse_path(char **str, t_cub *d)
{
	if (ft_strarrlen(str) == 2)
	{
		d->quant_par++;
		if (ft_strcmp(str[0], "NO") == 0 && ft_strlen(str[0]) == 2)
			nord_tex(str, str[1], d);
		else if (ft_strcmp(str[0], "SO") == 0 && ft_strlen(str[0]) == 2)
			south_tex(str, str[1], d);
		else if (ft_strcmp(str[0], "WE") == 0 && ft_strlen(str[0]) == 2)
			west_tex(str, str[1], d);
		else if (ft_strcmp(str[0], "EA") == 0 && ft_strlen(str[0]) == 2)
			east_tex(str, str[1], d);
	}
	else
	{
		ft_split_free(str);
		clean_up(d);
		ft_terror("Error\nTexture parameter fail\n");
	}
}
