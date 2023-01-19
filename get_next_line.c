/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:05 by gode-jes          #+#    #+#             */
/*   Updated: 2023/01/19 16:28:59 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	stack[BUFFER_SIZE + 1];
	char		*line;
	int			flag;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (read(fd, stack, BUFFER_SIZE) > 0)
	{
		printf("STACK: %s\n", stack);
		line = ft_strjoin(line, stack);
		printf("UPDATED_LINHA: %s\n", line);
		flag = update_stack(stack);
		printf("UPDATED_STACK: %s\n", stack);
		if (flag)
			break ;
	}
	printf("LINHA : %s", line);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("testfile", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}
