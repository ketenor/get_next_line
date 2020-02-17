/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:47:22 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/17 15:03:56 by ketenor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, s+i, 1);
		i++;
	}
	char c = '\n';
	write(1, &c, 1);
}


int main()
{
	int fd = open("text", O_RDONLY);
	char *line;
	line = malloc(1);
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		free(line);
	}
	free(line);
	close(fd);
	sleep (5);
	return (0);
}
