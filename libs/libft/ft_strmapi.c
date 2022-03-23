/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:00:56 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/19 23:58:11 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_str;
	unsigned int	i;

	ret_str = ft_strdup(s);
	if (!f || !s || !(ret_str))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret_str);
}
