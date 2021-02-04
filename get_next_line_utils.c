/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:00:40 by ster-min          #+#    #+#             */
/*   Updated: 2021/02/02 17:00:42 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_realloc(void *ptr, size_t size)
{
	void			*new_alloc = NULL;
	size_t			i;
	unsigned char 	*n;
	unsigned char 	*p;

	n = new_alloc;
	p = ptr;
	i = 0;
	if (!ptr)
		return ((void *)malloc(size));
	if (size <= sizeof(ptr))
		return (ptr);
	new_alloc = (void *)malloc(size);
	while (i < size)
	{
		*(n + i) = *(p + i);
		++i;
	}
	free(ptr);
	return (new_alloc);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}
