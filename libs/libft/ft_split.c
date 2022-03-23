/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:59:37 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/23 14:25:16 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count_words;

	if (s == NULL)
		return (0);
	i = 0;
	count_words = 0;
	while (s[i] && count_words >= 0)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count_words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count_words);
}

int	ft_split_utils(char const *s, int i, char c, int j)
{
	if (j)
	{
		while (s[i] == c && s[i])
			i++;
	}
	else
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		index;
	int		start;

	if (s != NULL)
		ret = malloc(sizeof(*ret) * (ft_count_words(s, c) + 1));
	if (s == NULL || ret == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		i = ft_split_utils(s, i, c, 1);
		if (s[i] != c && s[i])
		{
			start = i;
			i = ft_split_utils(s, i, c, 0);
			ret[index] = ft_substr(s, start, i - start);
			if (!(ret[index++]))
				return (NULL);
		}
	}
	ret[ft_count_words(s, c)] = NULL;
	return (ret);
}
