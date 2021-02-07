/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:00:53 by ster-min          #+#    #+#             */
/*   Updated: 2021/02/02 17:15:43 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
void	*ft_realloc(void *ptr, size_t size);
size_t	ft_strlen(const char *s);
int		ft_output(char *new_line, int st_i);

#endif
