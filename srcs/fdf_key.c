/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:35:10 by pcottet           #+#    #+#             */
/*   Updated: 2022/02/01 04:12:53 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_exit(t_trace_params *trace_params)
{
	int	i;

	i = 0;
	write (1, "free all then bye\n", 18);
	while (i < trace_params->map->row)
		free(trace_params->map->matrix[i++]);
	free(trace_params->map->matrix);
	free(trace_params->map);
	system("leaks fdf");
	exit (EXIT_SUCCESS);
}

int	deal_key(int key, t_trace_params *trace_params)
{
	if (key == MAIN_PAD_ESC)
		ft_exit(trace_params);
	if (key == MAIN_PAD_DOT)
		trace_params->z_plus -= 1;
	if (key == MAIN_PAD_COMMA)
		trace_params->arrow_mode = MODE_MOVE;
	if (key == MAIN_PAD_M)
		trace_params->arrow_mode = MODE_MOVE;
	if (key == MAIN_PAD_R)
		trace_params->arrow_mode = MODE_ROTA;
	if (key == MAIN_PAD_Z)
		trace_params->arrow_mode = MODE_ZOOM;
	if (key == ARROW_LEFT || key == ARROW_RIGHT || \
	key == ARROW_DOWN || key == ARROW_UP)
		ft_arrow_mode(key, trace_params);
	mlx_clear_window(trace_params->mlx_ptr, trace_params->win_ptr);
	ft_matrix_draw(trace_params->map, *trace_params);
	return (0);
}
