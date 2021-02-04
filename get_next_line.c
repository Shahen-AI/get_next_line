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

int get_next_line(int fd, char **line)
{
	static char	*new_line;
	size_t		n;
	size_t		i;
	char		*buff;

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
		printf("buff - %s\n", buff);
	while (i < n)
	{
		*(new_line + i) = *(buff + i);
		++i;
	}
	*(new_line + i) = '\0';
	free (buff);
	printf("new - %s\n", new_line);
	i = 0;
	while (new_line[i] != '\n' || new_line[i] != '\0')
	{
		*(line + i) = *(new_line + i);
		++i;
	}
	// *(line + i) = '\0';
		//printf("final - %s\n", line);

	return (0);
}

int main()
{
	char *buff;
	int a = open("test.txt", 0666);
	int n = get_next_line(a, &buff);

	// printf("%d\n", n);
	return (n);
}
