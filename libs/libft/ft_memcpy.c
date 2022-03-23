/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:58:21 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/10 12:13:36 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
