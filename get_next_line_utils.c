/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:14:03 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/06 00:11:22 by ketenor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strchr(char *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = -1;
	while (++i < ft_strlen(s))
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strncpy(char *s, char c)
{
	int		i;
	char	*res;
	int		cpt;

	if (!s)
		return (NULL);
	i = -1;
	cpt = 0;
	while (++i < ft_strlen(s) && s[i] != c)
		cpt++;
	if (!(res = malloc(cpt + 1)))
		return (NULL);
	i = -1;
	while (++i < cpt)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		fullsize;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	i = -1;
	j = -1;
	fullsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = malloc(fullsize)))
		return (NULL);
	while (++i < ft_strlen(s1))
		res[i] = s1[i];
	while (i - ft_strlen(s1) < ft_strlen(s2))
		res[i++] = s2[++j];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_shift(char *s, char c)
{
	int		i;
	int		j;
	char	*res;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(res = malloc(ft_strlen(s) - i)))
		return (NULL);
	while (++i < ft_strlen(s))
		res[j++] = s[i];
	res[j] = '\0';
	free(s);
	return (res);
}
