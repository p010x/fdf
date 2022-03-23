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

void	ft_xyz(t_trace_params *trace_params, t_matrix_coor coor, char c)
{
	if (c == START)
	{
		trace_params->x_start = coor.x + trace_params->move_x;
		trace_params->y_start = coor.y + trace_params->move_y;
		trace_params->z_start = coor.z + trace_params->move_z;
	}
	if (c == END)
	{
		trace_params->x_end = coor.x + trace_params->move_x;
		trace_params->y_end = coor.y + trace_params->move_y;
		trace_params->z_end = coor.z + trace_params->move_z;
	}
}

void	ft_matrix_draw(t_map *map, t_trace_params trace_params)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->row))
	{
		j = 0;
		while (j < (map->col))
		{
			ft_xyz(&trace_params, map->matrix[i][j], START);
			if (i + 1 < map->row)
				ft_xyz(&trace_params, map->matrix[i + 1][j], END);
			ft_trace_vector(trace_params);
			if (j + 1 < map->col)
				ft_xyz(&trace_params, map->matrix[i][j + 1], END);
			ft_trace_vector(trace_params);
			j++;
		}
		i++;
	}
}

int	ft_height_color(t_matrix_coor *matrix_coor, int x, int y, \
char *height_color)
{
	char	**height_color_arr;

	height_color_arr = ft_split(height_color, ',');
	if (height_color_arr == NULL)
		return (0);
	matrix_coor->x = x;
	matrix_coor->y = y;
	matrix_coor->z = ft_atoi(height_color_arr[0]);
	if (height_color_arr[1])
	{
		matrix_coor->color = ft_hex_to_i(height_color_arr[1], \
		ft_strlen(height_color_arr[1]) - 1);
		free(height_color_arr[1]);
	}
	else
		matrix_coor->color = 0XFFFFFF;
	free(height_color_arr[0]);
	free(height_color_arr);
	return (1);
}

void	ft_build_matrix(t_list *map_coor, t_trace_params *trace_params)
{
	int		i;
	int		y;
	t_list	*map_coor_start;
	int		ret;

	y = -200;
	i = 0;
	map_coor_start = map_coor;
	ret = ft_matrix_loop(map_coor, trace_params, i, y);
	ft_free_lst(map_coor_start);
	if (!ret)
		ft_exit_error(ERROR_MALLOC);
}

void	ft_get_map(t_trace_params *trace_params)
{
	t_list	*map_coor;

	map_coor = ft_map_lst(trace_params);
	while (((char **)(map_coor->content))[trace_params->map->col])
		trace_params->map->col++;
	trace_params->map->matrix = malloc(\
	sizeof(trace_params->map->matrix) * trace_params->map->row);
	if (trace_params->map->matrix == NULL)
		ft_free_exit(trace_params, (void *)ft_free_lst, map_coor);
	ft_prepare_matrix(trace_params, map_coor);
	trace_params->px_space = ft_px_btw(trace_params);
	ft_build_matrix(map_coor, trace_params);
}
