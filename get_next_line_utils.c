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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	n;
	size_t	m;

	n = ft_strlen(s1);
	m = ft_strlen(s2);
	if (!(res = (char *)malloc((n + m + 1) * sizeof(*res))))
		return (NULL);
	ft_strlcpy(res, s1, n + 1);
	ft_strlcat(res, s2, m + n + 1);
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	len = 0;
	i = 0;
	if (!src || !dest)
		return (0);
	if (size > 1)
	{
		while (i < (size - 1) && *(src + i))
		{
			*(dest + i) = *(src + i);
			++i;
		}
		*(dest + i) = '\0';
	}
	while (*(src + len))
		++len;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t d_len;
	size_t s_len;

	d_len = 0;
	i = 0;
	s_len = 0;
	while (*(dest + d_len) && d_len < size)
		++d_len;
	while (*(src + s_len))
		++s_len;
	while (d_len + i + 1 < size && *(src + i))
	{
		*(dest + d_len + i) = *(src + i);
		++i;
	}
	if (i != 0)
		*(dest + d_len + i) = '\0';
	return (s_len + d_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;
	size_t	s_len;
	size_t	over_len;

	index = 0;
	if (!s)
		return (NULL);
	over_len = ft_strlen(s + start);
	if (len > over_len)
		len = over_len;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (!(res = (char *)malloc((len + 1) * sizeof(*res))))
		return (NULL);
	while (index < len && start + index < s_len)
	{
		*(res + index) = *(s + start + index);
		++index;
	}
	*(res + len) = '\0';
	return (res);
}
