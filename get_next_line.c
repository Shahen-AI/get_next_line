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
	int i;
	char **buff;

	if (!(buff = (char *)malloc(sizeof(char))))
		return (0);
	read(fd, buff, 1);
	i = 0;
	while (buff[i + 1] != '\0')
	{
		read(fd, buff, 1 + i);
		++i;
		ft_realloc(buff, i);
	}
	if (!(buff = (char *)malloc(sizeof(char **) * i)))
		return (0);
	i = 0;
	while (buff[i] != '\n' || buff[i] != '\0')
	{
		line[i] = buff[i];
		++i;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i = 1;
	}
	else if (buff[i] == '\0')
	{
		line[i] = '\0';
		i = 0;
	}
	else
		i = -1;
	return (i);
}

int main()
{
	char **buff;
	buff = malloc(sizeof(char **) * 100);
	int a = open("test.txt", 0666);
	read(a, buff, 6);
	printf("%s\n", buff);

	int n = get_next_line(a, buff);
	printf("%s\n", buff);

	printf("%d\n", n);
	return (0);
}
