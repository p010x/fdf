/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:23:21 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/19 17:47:49 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		s1 = "";
	else if (!s2)
		s2 = "";
	ret_str = malloc(sizeof(*ret_str) * (ft_strlen(s1) \
	+ ft_strlen(s2) + 1));
	if (!(ret_str))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ret_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret_str[i++] = s2[j++];
	ret_str[i] = '\0';
	return (ret_str);
}
