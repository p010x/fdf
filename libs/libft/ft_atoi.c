/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:21:36 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/19 10:38:40 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overflow_handler(unsigned long ret_value, long sign, int j)
{
	unsigned long	max_long;
	unsigned long	min_long;

	max_long = 9223372036854775807;
	min_long = 9223372036854775807;
	if (j > 19)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	if (sign > 0 && ret_value > max_long)
		return (-1);
	if (sign < 0 && ret_value > min_long + 1)
		return (0);
	return ((int)((long)ret_value * sign));
}

int	ft_isspace(char c)
{
	return ((c == '\t' || c == '\r' || c == '\n' || c == '\v' || \
		c == '\f' || c == ' '));
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	ret_value;
	long			sign;
	int				j;

	i = 0;
	j = 0;
	sign = 1;
	ret_value = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret_value *= 10;
		ret_value += (str[i] - '0');
		i++;
		j++;
	}
	return (ft_overflow_handler(ret_value, sign, j));
}
