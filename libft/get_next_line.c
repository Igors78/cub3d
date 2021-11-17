/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:24:31 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/17 21:15:13 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	i = 0;
	rd = 1;
	buffer = malloc(1000);
	ch = ' ';
	*line = buffer;
	while (rd > 0 && ch != '\n')
	{
		rd = read(fd, &ch, 1);
		if (ch == '\n')
			break ;
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return (rd);
}
