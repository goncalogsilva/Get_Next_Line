/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:05 by gode-jes          #+#    #+#             */
/*   Updated: 2023/02/13 18:35:19 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buff[i])
			buff[i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		flag = update_buffer(buff);
		if (flag)
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*linha;

// 	fd = open("testfile", O_RDONLY);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	linha = get_next_line(fd);
// 	printf("LINHA: %s", linha);
// 	close(fd);
// 	return (0);
// }
