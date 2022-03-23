/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:41:42 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/31 18:09:41 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_exit(t_trace_params *trace_params, void (*f)(void *), void *ptr)
{
	if (ptr != NULL && f != NULL)
		f(ptr);
	free(trace_params->map);
	ft_exit_error(ERROR_MALLOC);
}

int	ft_check_lst_content(t_list *lst)
{
	while (lst)
	{
		if (lst->content == NULL)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_map_lst(t_trace_params *trace_params)
{
	char	*line;
	t_list	*map_coor;
	t_list	*map_coor_start;

	map_coor = NULL;
	line = get_next_line(trace_params->fd);
	if (line == NULL)
		ft_free_exit(trace_params, NULL, NULL);
	ft_lstadd_back(&map_coor, ft_lstnew(ft_split(line, ' ')));
	if (map_coor == NULL)
		ft_free_exit(trace_params, free, line);
	map_coor_start = map_coor;
	trace_params->map->row++;
	free(line);
	line = get_next_line(trace_params->fd);
	while (line)
	{
		ft_lstadd_back(&map_coor, ft_lstnew(ft_split(line, ' ')));
		if (!ft_check_lst_content(map_coor_start))
			ft_free_exit(trace_params, (void *)ft_free_lst, map_coor_start);
		trace_params->map->row++;
		free(line);
		line = get_next_line(trace_params->fd);
	}
	return (map_coor);
}

void	ft_prepare_matrix(t_trace_params *trace_params, t_list *map_coor)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < trace_params->map->row)
	{
		trace_params->map->matrix[i] = malloc(\
		sizeof(t_matrix_coor) * trace_params->map->col);
		if (trace_params->map->matrix[i] == NULL)
		{
			while (j <= i)
				free(trace_params->map->matrix[j++]);
			free(trace_params->map->matrix);
			ft_free_exit(trace_params, (void *)ft_free_lst, map_coor);
		}
		i++;
	}
}

int	ft_matrix_loop(t_list *map_coor, t_trace_params *trace_params, int i, int y)
{
	int		j;
	int		x;
	int		ret;

	while (map_coor)
	{
		j = 0;
		x = WIN_WIDTH * 0.4;
		while (((char **)(map_coor->content))[j])
		{
			ret = ft_height_color(&trace_params->map->matrix[i][j], x, y, \
			((char **)(map_coor->content))[j]);
			if (!ret)
				return (ret);
			x += trace_params->px_space;
			j++;
		}
		y += trace_params->px_space;
		map_coor = map_coor->next;
		i++;
	}
	return (ret);
}
