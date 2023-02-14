/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:05 by gode-jes          #+#    #+#             */
/*   Updated: 2023/02/14 12:26:27 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		while (fd < FOPEN_MAX && fd >= 0 && buff[fd][i])
			buff[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		flag = update_buffer(buff[fd]);
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
