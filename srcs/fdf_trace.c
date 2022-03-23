/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:35:05 by pcottet           #+#    #+#             */
/*   Updated: 2022/02/01 04:07:03 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_trace_delta(t_trace_params trace_params)
{
	if (trace_params.delta_x > 0)
	{
		if (trace_params.delta_y > 0)
			ft_trace_quadrant(trace_params, 1);
		if (trace_params.delta_y < 0)
			ft_trace_quadrant(trace_params, 4);
	}
	if (trace_params.delta_x < 0)
	{
		if (trace_params.delta_y > 0)
			ft_trace_quadrant(trace_params, 2);
		if (trace_params.delta_y < 0)
			ft_trace_quadrant(trace_params, 3);
	}
	return (1);
}

int	ft_trace_no_delta(t_trace_params trace_params)
{
	if (trace_params.delta_y != 0 || trace_params.delta_x == 0)
	{
		if (trace_params.delta_y > 0)
			ft_trace_xy_vector(trace_params, 0, 1);
		if (trace_params.delta_y < 0)
			ft_trace_xy_vector(trace_params, 0, -1);
	}
	if (trace_params.delta_x != 0 || trace_params.delta_y == 0)
	{
		if (trace_params.delta_x > 0)
			ft_trace_xy_vector(trace_params, 1, 0);
		if (trace_params.delta_x < 0)
			ft_trace_xy_vector(trace_params, -1, 0);
	}
	return (1);
}

void	ft_view(t_trace_params *trace_params)
{
	trace_params->z_start *= trace_params->z_plus;
	trace_params->z_end *= trace_params->z_plus;
	ft_rotate_view(trace_params);
	ft_iso_view(trace_params);
}

int	ft_trace_vector(t_trace_params trace_params)
{
	ft_view(&trace_params);
	trace_params.delta_x = trace_params.x_end - trace_params.x_start;
	trace_params.delta_y = trace_params.y_end - trace_params.y_start;
	if (trace_params.delta_x == 0 || trace_params.delta_y == 0)
		ft_trace_no_delta(trace_params);
	else
		ft_trace_delta(trace_params);
	return (1);
}
