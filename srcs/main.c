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

int	ft_px_btw(t_trace_params *trace_params)
{
	if (trace_params->map->col >= trace_params->map->row)
	{
		return ((WIN_WIDTH / trace_params->map->col) * trace_params->zoom);
	}
	if (trace_params->map->col < trace_params->map->row)
	{
		return (WIN_WIDTH / trace_params->map->row * trace_params->zoom);
	}
	return (10);
}

int	ft_init_params(t_trace_params *trace_params)
{
	trace_params->angle = 0.6;
	trace_params->angle_rotation = 0.15;
	trace_params->z_plus = 3;
	trace_params->zoom = 0.6;
	trace_params->arrow_mode = MODE_ROTA;
	trace_params->move_x = 0;
	trace_params->move_y = 0;
	trace_params->move_z = 0;
	trace_params->map = malloc(sizeof(t_map));
	if (!(trace_params->map))
		exit(EXIT_FAILURE);
	trace_params->map->col = 0;
	trace_params->map->row = 0;
	ft_get_map(trace_params);
	trace_params->mlx_ptr = mlx_init();
	trace_params->win_ptr = mlx_new_window(trace_params->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "Fdf Window");
	return (1);
}

int	main(int argc, char **argv)
{
	t_trace_params	trace_params;

	if (argc < 2)
		ft_exit_error(ERROR_FILE);
	ft_checkmap(argv[1]);
	trace_params.fd = open(argv[1], O_RDONLY);
	if (trace_params.fd < 0)
		ft_exit_error(ERROR_FD);
	ft_init_params(&trace_params);
	ft_matrix_draw(trace_params.map, trace_params);
	mlx_key_hook(trace_params.win_ptr, deal_key, &trace_params);
	mlx_loop(trace_params.mlx_ptr);
	return (1);
}
