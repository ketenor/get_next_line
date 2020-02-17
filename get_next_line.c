/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:13:32 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/17 16:56:07 by ketenor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		none_read(int nbread, char *buff)
{
	if (nbread < 0 && buff)
	{
		free(buff);
		return (1);
	}
	return (0);
}

void	free_text(char **text)
{
	free(*text);
	*text = NULL;
}

int		get_next_line(int fd, char **line)
{
	static	char	*text = NULL;
	char			*buff;
	int				nb_read;
	int				res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0
			|| !(buff = malloc(BUFFER_SIZE + 1))
			|| (!text && (!(text = malloc(1))
			|| (*text = '\0'))))
		return (-1);
	while (!ft_strchr(text, '\n')
			&& (nb_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nb_read] = '\0';
		text = ft_strcat(text, buff);
	}
	free(buff);
	*line = ft_strncpy(text, '\n');
	res = ft_strchr(text, '\n');
	text = ft_shift(text, '\n');
	if (nb_read == -1)
		return (-1);
	if (!res)
		free_text(&text);
	return (res);
}
