/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:23:43 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 21:25:03 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	line_symb(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'W' && s[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

static void	line_map(char *s, t_cub *d)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(s, ' ');
	while (arr[i])
	{
		if (arr[i][0] != '1' || arr[i][ft_strlen(arr[i]) - 1] != '1'
		|| line_symb(arr[i]))
		{
			ft_split_free(arr);
			inv_map(d);
		}
		i++;
	}
	ft_split_free(arr);
}

static void	map_deepcheck(t_cub *d)
{
	int	w;
	int	h;

	w = 0;
	h = 1;
	while (d->map_strings[0][w])
	{
		if (d->map_strings[0][w] != '1' && d->map_strings[0][w] != ' ')
			inv_map(d);
		w++;
	}
	w = 0;
	while (d->map_strings[d->map_h - 1][w])
	{
		if (d->map_strings[d->map_h - 1][w] != '1'
		&& d->map_strings[d->map_h - 1][w] != ' ')
			inv_map(d);
		w++;
	}
	while (h < d->map_h - 1)
	{
		line_map(d->map_strings[h], d);
		h++;
	}
}

static void	map_strarr(int fd, char *line, t_cub *d)
{
	d->map_strings = ft_addstrstrarr(d->map_strings, line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
		{
			d->flag = 1;
			free(line);
			continue ;
		}
		if (d->flag)
		{
			free(line);
			inv_map(d);
		}
		d->map_strings = ft_addstrstrarr(d->map_strings, line);
		free(line);
	}
	if (line[0] != '\0')
		d->map_strings = ft_addstrstrarr(d->map_strings, line);
	free(line);
	d->map_h = ft_strarrlen(d->map_strings);
	if (d->map_h < 3)
		inv_map(d);
	map_deepcheck(d);
}

void	parse_map(int fd, t_cub *d)
{
	char	*line;
	int		gnl;

	line = NULL;
	gnl = get_next_line(fd, &line);
	if (gnl <= 0)
	{
		free(line);
		inv_map(d);
	}
	while ((line[0] == '\n' || line[0] == '\0') && gnl == 1)
	{
		free(line);
		line = NULL;
		gnl = get_next_line(fd, &line);
	}
	if (NULL == line || gnl <= 0)
	{
		free(line);
		inv_map(d);
	}
	map_strarr(fd, line, d);
}
