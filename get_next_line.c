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

void		go_to_next(char **new_line, int st_i)
{
	*new_line += (st_i + 1);
}

char		*get_line(char *new_line, int st_i)
{
	char	*line;
	int 	i;

	i = 0;
	if (!(line = malloc(sizeof(char) * (1 + st_i))))
		return (0);
	while (i < st_i)
	{
		line[i] = new_line[i];
		++i;
	}
	line[st_i] = '\0';
	return (line);
}

static int	nxtl(char *new_line, int st_i)
{
	char	*line;

	while (new_line[st_i] != '\n' && new_line[st_i] != '\0')
	{
		++st_i;
	}
	return (st_i);
}

int		ft_output(char *new_line, int st_i)
{
	int i;

	i = 0;
	if (new_line[st_i] == '\n')
		i = 1;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*new_line;
	size_t		n;
	size_t		i;
	char		buff[BUFFER_SIZE];
	static int	st_i;
	ssize_t		ret;

	if(fd < 0 || !*line || BUFFER_SIZE <= 0)
		return (-1);
	if (!new_line && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		i = 0;
		n = ft_strlen(buff);
		if (!(new_line = malloc(n + 1)))
			return (-1);
		while (i < n)
		{
			new_line[i] = buff[i];
			++i;
		}
		new_line[i + 1] = '\0';
	}
	st_i = 0;
	st_i = nxtl(new_line, st_i);
	*line = get_line(new_line, st_i);
	int	k = ft_output(new_line, st_i);
	go_to_next(&new_line, st_i);
	// printf("sti - %d ===   %s\n", st_i, new_line);
	return (k);
}

int main()
{
	char *buff;
	int a = open("test.txt", 0666);
	int n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	
	return (0);
}
