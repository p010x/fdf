/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:38:18 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/19 11:47:04 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

int	ft_count_set(char const *s1, char const *set)
{
	int		i;
	int		count_set;

	i = 0;
	count_set = 0;
	while (s1[i] && ft_is_set(s1[i], set))
	{
		count_set++;
		i++;
	}
	if (i == ft_strlen(s1))
		return (i);
	i = ft_strlen(s1) - 1;
	while (i && ft_is_set(s1[i], set))
	{
		count_set++;
		i--;
	}
	return (count_set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ret_str;

	ret_str = malloc(sizeof(*s1) * (ft_strlen(s1) - ft_count_set(s1, set) + 1));
	if (!s1 || !(ret_str))
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = 0;
	while (i >= 0 && s1[i])
	{
		ret_str[j++] = s1[i++];
		k = 0;
		while (i >= 0 && ft_is_set(s1[i + k], set))
		{
			if (!s1[i + k + 1])
				i = -1;
			k++;
		}
	}
	ret_str[j] = '\0';
	return (ret_str);
}
