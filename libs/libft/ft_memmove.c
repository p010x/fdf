/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:12:38 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/29 04:04:53 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
