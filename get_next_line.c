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
	char *buff;

	if (!(buff = (char *)malloc(sizeof(char))))
		return (0);
	i = 0;
	while (buff[i] != '\0')
	{
		read(fd, buff, 1 + i);
		++i;
		ft_realloc(buff, i);
	}
	return (i);
}

int main()
{
	char buff[100];
	int a = open("test.txt", 0666);
	read(a, buff, 4);
	char **string;

	// int n = get_next_line(a, buff);
		printf("%s\n", buff);

	// printf("%d\n", n);
	return (0);
}
