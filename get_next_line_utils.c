/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:58:47 by gode-jes          #+#    #+#             */
/*   Updated: 2023/01/11 13:09:45 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' /*&& s[i] != '\n'*/)
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = (char *) malloc(size_s1 + size_s2 + 1);
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + 1);
	ft_strlcpy(str + size_s1, s2, size_s2 + 1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s);
	dup = (char *) malloc(len * sizeof(char) + 1);
	if (dup == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	update_str(char *str, char **line)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_strdup(str);
		(*line)[i + 1] = '\0';
		j = i;
		while (str[j] != '\0')
		{
			str[j - i] = str[j + 1];
			j++;
		}
		return (1);
	}
	return (0);
}
