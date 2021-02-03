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
	void	*new_alloc;
	int		i;
	unsigned char *n;
	unsigned char *p;

	n = new_alloc;
	p = ptr;
	i = 0;
	if (!ptr)
		return (NULL);
	if (!(new_alloc = (void *)malloc(sizeof(*new_alloc) * size)))
		return (NULL);
	while (i < size)
	{
		*(n + i) = *(p + i);
		++i;
	}
	free(ptr);
	return (new_alloc);
}
