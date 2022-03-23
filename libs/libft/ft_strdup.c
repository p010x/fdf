/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:02:53 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:17:43 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret_str;
	int		i;

	i = 0;
	ret_str = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!(ret_str))
		return (NULL);
	while (s1[i])
	{
		ret_str[i] = s1[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
