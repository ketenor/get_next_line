/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:13:32 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/13 12:05:53 by ketenor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	none_read(int nbread, char *buff)
{
	if (nbread < 0)
	{
		free(buff);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static	char	*text = NULL;
	char			*buff;
	int				nb_read;
	int				res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0
			|| !(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!text && !((text = malloc(1))))
	{
		*text = '\0';
		return (-1);
	}
	while (!ft_strchr(text, '\n') && (nb_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nb_read] = '\0';
		text = ft_strcat(text, buff);
	}
    *line = ft_strncpy(text, '\n');
    res = ft_strchr(text, '\n');
    text = ft_shift(text, '\n');
	if (none_read(nb_read, buff))
        return (-1);
	free(buff);
	return (res);
}
