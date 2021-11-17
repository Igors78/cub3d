/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:29:48 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 21:22:23 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	parse_id(char **str, t_cub *d)
{
	if ((ft_strcmp(str[0], "NO") == 0 && ft_strlen(str[0]) == 2)
		|| (ft_strcmp(str[0], "SO") == 0 && ft_strlen(str[0]) == 2)
		|| (ft_strcmp(str[0], "WE") == 0 && ft_strlen(str[0]) == 2)
		|| (ft_strcmp(str[0], "EA") == 0 && ft_strlen(str[0]) == 2))
		parse_path(str, d);
	else if (ft_strcmp(str[0], "F") == 0 && ft_strlen(str[0]) == 1)
		parse_floor(str, d);
	else if (ft_strcmp(str[0], "C") == 0 && ft_strlen(str[0]) == 1)
		parse_ceil(str, d);
	else
	{
		ft_split_free(str);
		clean_up(d);
		ft_terror("Error\nWrong parameter list");
	}
}

static void	parse_config(int fd, t_cub *d)
{
	char	*line;
	char	**str;
	int		gnl;

	line = NULL;
	while (d->quant_par != 6)
	{
		gnl = get_next_line(fd, &line);
		if (gnl <= 0)
		{
			free(line);
			clean_up(d);
			ft_terror("Error\nNot valid map file");
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		str = ft_split(line, ' ');
		free(line);
		parse_id(str, d);
		ft_split_free(str);
	}
	parse_map(fd, d);
}

void	read_config(char *path, t_cub *d)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		clean_up(d);
		ft_terror("Error\nNot valid map file");
	}
	parse_config(fd, d);
	close(fd);
	parse_doubles(d->map_strings, d);
}
