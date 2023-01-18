/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:05 by gode-jes          #+#    #+#             */
/*   Updated: 2023/01/18 12:15:37 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str;
	char		stack[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		i = read(fd, stack, BUFFER_SIZE);
		stack[BUFFER_SIZE] = '\0';
		/*printf("STACK: %s\n", stack);*/
		str = ft_strjoin(str, stack);
		/*printf("STR: %s\n", str);*/
		flag = update_str(str, &line);
		/*printf("U_STR: %s\n", str);*/
		if (flag || !i)
		{
			free(str);
			break ;
		}
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
