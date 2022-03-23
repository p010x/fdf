/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:35:05 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/31 18:43:52 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso_view(t_trace_params *trace_params)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = trace_params->x_start;
	x_end = trace_params->x_end;
	y_start = trace_params->y_start;
	y_end = trace_params->y_end;
	trace_params->x_start = (x_start - y_start) * cos(trace_params->angle);
	trace_params->x_end = (x_end - y_end) * cos(trace_params->angle);
	trace_params->y_start = ((-trace_params->z_start + \
	(x_start + y_start) * sin(trace_params->angle)));
	trace_params->y_end = ((-trace_params->z_end + (x_end + y_end) \
	* sin(trace_params->angle)));
}

void	ft_rotate_view(t_trace_params *trace_params)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = trace_params->x_start;
	x_end = trace_params->x_end;
	y_start = trace_params->y_start;
	y_end = trace_params->y_end;
	trace_params->x_start = ((x_start * cos(trace_params->angle_rotation)) \
	- (y_start * sin(trace_params->angle_rotation)));
	trace_params->x_end = ((x_end * cos(trace_params->angle_rotation)) - \
	(y_end * sin(trace_params->angle_rotation)));
	trace_params->y_start = ((x_start * sin(trace_params->angle_rotation)) + \
	(y_start * cos(trace_params->angle_rotation)));
	trace_params->y_end = ((x_end * sin(trace_params->angle_rotation)) + \
	(y_end * cos(trace_params->angle_rotation)));
}
