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

int		get_next_line(int fd, char **line);
void	*ft_realloc(void *ptr, size_t size);

#endif
