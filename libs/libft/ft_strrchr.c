/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:18:18 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:19:53 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_c;

	i = 0;
	last_c = 0;
	while (s[i])
	{
		if (s[i] == c)
			last_c = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		last_c = (char *)&s[i];
	return (last_c);
}
