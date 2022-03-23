/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:50:54 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/29 04:29:00 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;
	size_t					i;

	dst_tmp = dst;
	src_tmp = src;
	i = 0;
	while (n--)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buffer;

	if (!dst && !src)
		return (dst);
	buffer = NULL;
	if (len)
		buffer = malloc(len);
	if (buffer)
	{
		ft_memcpy(buffer, src, len);
		ft_memcpy(dst, buffer, len);
	}
	free(buffer);
	return (dst);
}

ssize_t	find_new_line(char *s, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*merge_lines(char *s1, ssize_t size1, char *s2, ssize_t size2)
{
	char	*s;

	s = malloc(sizeof(char) * (size1 + size2 + 1));
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, s1, size1);
	ft_memcpy(&s[size1], s2, size2);
	s[size1 + size2] = '\0';
	return (s);
}
