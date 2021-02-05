/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:00:19 by ster-min          #+#    #+#             */
/*   Updated: 2021/02/02 17:00:21 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nxtl(char *new_line, int st_i)
{
	char	*line;
	int		i;

	i = 0;
	if (!new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		++i;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (new_line[st_i] != '\n' && new_line[st_i] != '\0')
	{
		line[st_i] = new_line[st_i];
		++st_i;
	}
	line[st_i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char	*new_line;
	size_t		n;
	size_t		i;
	char		*buff;
	static int	st_i;

	if(fd <= 0 || !*line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, buff, BUFFER_SIZE) == -1)
	{
		free(buff);
		return (-1);
	}
	buff[BUFFER_SIZE] = '\0';
	i = 0;
	n = ft_strlen(buff);
	if (!(new_line = malloc(n)))
		return (-1);
	while (i < n)
	{
		*(new_line + i) = *(buff + i);
		++i;
	}
	*(new_line + i) = '\0';
	free (buff);
	st_i = 0;
	*line = nxtl(new_line, st_i);
	printf("%d\n", st_i);
	return (0);
}

int main()
{
	char *buff;
	int a = open("test.txt", 0666);
	int n = get_next_line(a, &buff);
	get_next_line(a, &buff);


	// printf("%d\n", n);
	return (n);
}
