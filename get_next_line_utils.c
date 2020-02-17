/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketenor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:14:03 by ketenor           #+#    #+#             */
/*   Updated: 2020/02/17 16:40:29 by ketenor          ###   ########.fr       */
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
	while (s[++i] && s[i] != c)
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
	int		size1;
	int		size2;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	i = -1;
	j = -1;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(res = malloc(size1 + size2 + 1)))
		return (NULL);
	while (++i < size1)
		res[i] = s1[i];
	while (i - size1 < size2)
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

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
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
