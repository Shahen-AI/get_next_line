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

// void		go_to_next(char **new_line, int st_i)
// {
// 	*new_line += (st_i + 1);
// }

char	*get_line(char *str, int len)
{
	char	*temp;
	int 	i;
	int		n;

	n = ft_strlen(str);
	i = 0;
	if (!(temp = malloc(n - len + 1)))
		return (NULL);
	while (str[i + len])
	{
		temp[i] = str[i + len];
		++i;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

int		bsn_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	return (0);
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
	char		buff[BUFFER_SIZE + 1];
	ssize_t		ret;
	int			len;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	// if(!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	// 	return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		printf("TEST");
		new_line = ft_strjoin(new_line, buff);
		if ((len = bsn_len(new_line)) != 0)
		{
			*line = ft_substr(new_line, 0, len);
			new_line = get_line(new_line, len);
			break ;
		}
	}
	// free(buff);
	return (0);
}

int main()
{
	char *buff;
	int a = open("test.txt", 0666);
	int n = get_next_line(a, &buff);
	printf("main(return - %d) - %s\n", n, buff);
	// n = get_next_line(a, &buff);
	// printf("main(return - %d) - %s\n", n, buff);
	// n = get_next_line(a, &buff);
	// printf("main(return - %d) - %s\n", n, buff);
	// n = get_next_line(a, &buff);
	// printf("main(return - %d) - %s\n", n, buff);
	// n = get_next_line(a, &buff);
	// printf("main(return - %d) - %s\n", n, buff);
	// n = get_next_line(a, &buff);
	// printf("main(return - %d) - %s\n", n, buff);

	// i = 0;
	// while(i<10){
	// 	printf("%d - %d\n", i, arr[i]);
	// 	++i;}
	// free(arr);
	return (0);
}
