/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 03:59:02 by pcottet           #+#    #+#             */
/*   Updated: 2022/02/01 04:12:02 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue ;
		}
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit_error(int error_code)
{
	if (error_code == ERROR_FD)
		ft_putstr_fd("\n-- Error file --\n", 1);
	if (error_code == ERROR_FILE)
		ft_putstr_fd("\n-- No file --\n", 1);
	if (error_code == ERROR_MAP)
		ft_putstr_fd("\n-- Wrong map format --\n", 1);
	if (error_code == ERROR_MALLOC)
		ft_putstr_fd("\n-- Fail to malloc --\n", 1);
	system("leaks fdf");
	exit(error_code);
}

void	ft_free_lst(t_list *lst)
{
	t_list	*lst_tmp;
	int		i;

	while (lst)
	{
		i = 0;
		while (((char **)(lst->content))[i])
			free(((char **)(lst->content))[i++]);
		free(lst->content);
		lst_tmp = lst;
		lst = lst->next;
		free(lst_tmp);
	}
}

int	ft_str_pos(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_hex_to_i(char *str, int hex_size)
{
	int		i;
	int		res;
	int		pos;
	char	*hex;

	hex = malloc(sizeof(char) * hex_size);
	if (hex == NULL)
		return (255);
	ft_strlcpy(hex, &str[2], hex_size);
	i = 0;
	res = 0;
	hex_size--;
	if (hex[hex_size - 1] == '\n')
		hex_size--;
	while (--hex_size >= 0)
	{
		pos = ft_str_pos("0123456789ABCDEF", ft_toupper(hex[hex_size]));
		if (pos < 0)
			break ;
		res += pos * (int)pow((double)16, (double)i);
		i++;
	}
	free(hex);
	return (res);
}
