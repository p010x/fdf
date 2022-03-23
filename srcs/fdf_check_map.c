/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:46:05 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/31 18:14:10 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_count_entries(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	ft_check_cond(char **vals)
{
	int	ret;
	int	count;

	ret = 1;
	count = ft_count_entries(vals);
	if (count < 1)
	{
		ft_putstr_fd("\nMissing coordinates\n", 1);
		ft_free_array(vals);
		return (0);
	}
	if (count > 2)
	{
		ft_putstr_fd("\nTo much values (only one coma accepted)\n", 1);
		ret = 0;
	}
	if (ft_str_isdigit(vals[0]) == 0)
	{
		ft_putstr_fd("\nOnly digits are accepted (0-9) for coordinates\n", 1);
		ret = 0;
	}
	ft_free_array(vals);
	return (ret);
}

int	ft_check_matrix(char **matrix, int *count)
{
	int		i;
	char	**vals;
	int		ret;

	i = 0;
	ret = 1;
	while (matrix[i])
	{
		vals = ft_split(matrix[i], ',');
		ret = ft_check_cond(vals);
		i++;
		if (ret == 0)
			break ;
	}
	ft_free_array(matrix);
	if (*count > 0)
	{
		if (*count != i)
		{
			ft_putstr_fd("\nMissmatch colums lenght\n", 1);
			ret = 0;
		}
	}
	*count = i;
	return (ret);
}

void	ft_checkmap(char *file)
{
	int		fd;
	char	*line;
	char	**matrix;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_error(ERROR_FD);
	count = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_exit_error(ERROR_MAP);
	while (line)
	{
		matrix = ft_split(line, ' ');
		free(line);
		if (matrix == NULL || matrix[0] == NULL)
			ft_exit_error(ERROR_MAP);
		if (ft_check_matrix(matrix, &count) == 0)
			ft_exit_error(ERROR_MAP);
		line = get_next_line(fd);
	}
}
