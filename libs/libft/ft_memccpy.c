/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:04:47 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/10 12:16:31 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_tmp;
	const unsigned char		*src_tmp;
	size_t					i;

	if (!dst && !src)
		return (NULL);
	dst_tmp = dst;
	src_tmp = src;
	i = 0;
	while (n--)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i++] == (unsigned char)c)
			return (&dst[i]);
	}
	return (NULL);
}
