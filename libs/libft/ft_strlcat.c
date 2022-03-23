/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:44:19 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/10 12:25:46 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret_value;
	size_t	dst_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		ret_value = ft_strlen(src) + dstsize;
	else
		ret_value = ft_strlen(src) + dst_len;
	while (src[i] && dst_len < (dstsize - 1) && dstsize)
		dst[dst_len++] = src[i++];
	dst[dst_len] = '\0';
	return (ret_value);
}
