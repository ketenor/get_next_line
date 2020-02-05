/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:14:13 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/06 00:09:23 by ketenor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);
int		ft_strchr(char *s, char c);
int		none_read(int nbread, char *buff);
char	*ft_strncpy(char *s, char c);
char	*ft_strcat(char *s1, char *s2);
char	*ft_shift(char *s, char c);

#endif
