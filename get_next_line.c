/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:53:05 by gode-jes          #+#    #+#             */
/*   Updated: 2023/01/11 13:11:13 by gode-jes         ###   ########.fr       */
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

	if (fd < 0 && BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (read(fd, stack, BUFFER_SIZE))
	{
		stack[BUFFER_SIZE] = '\0';
		/*printf("stack: %s/\n", stack);*/
		str = ft_strjoin(str, stack);
		line = (char *) malloc(ft_strlen(str) * sizeof(char));
		if (line == 0)
			return (NULL);
		printf("str: %s/\n", str);
		flag = update_str(str, &line);
		printf("STR_U : %s\n", str);
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
	/*get_next_line(fd);*/
	close(fd);
	return (0);
}
