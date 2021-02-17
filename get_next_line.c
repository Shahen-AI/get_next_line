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

int		bsn_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '\n')
		return (1);
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

char	*get_line(char *str, int len)
{
	char	*temp;
	int 	i;
	int		n;

	n = ft_strlen(str);
	i = 0;
	if (!str)
		return ('\0');
	if (!(temp = malloc(n - len)))
		return (NULL);
	if (str[i] == '\n')
		--len;
	while (str[len + i + 1])
	{
		temp[i] = str[i + len + 1];
		++i;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

int		bsn_check(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\n')
		return (1);
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
	if (!new_line)
		return (0);
	if (new_line[0] == '\n')
		return (1);
	if (new_line[st_i] == '\n')
		i = 1;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	*new_line;
	char		*buff;
	ssize_t		ret;
	int			len;
	int 		out;

	out = 0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if(!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		new_line = ft_strjoin(new_line, buff);
		if (bsn_check(new_line))
			break ;
	}
	len = bsn_len(new_line);
	out = ft_output(new_line, len);
	*line = ft_substr(new_line, 0, len);
	new_line = get_line(new_line, len);
	free(buff);
	return (out);
}

int main()
{
	char *buff;
	int a = open("test.txt", 0666);
	int n = 1;

	while (n)
	{
		n = get_next_line(a, &buff);
		printf("main(return - %d) - %s\n", n, buff);
	}
	
	return (0);
}
