/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:35:05 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/31 18:46:47 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_trace_xy_vector(t_trace_params trace_params, int x, int y)
{
	while (1)
	{
		mlx_pixel_put(trace_params.mlx_ptr, trace_params.win_ptr, \
		trace_params.x_start, trace_params.y_start, WHITE);
		trace_params.x_start += x;
		trace_params.y_start += y;
		if ((trace_params.x_end == trace_params.x_start && x) || \
		(trace_params.y_end == trace_params.y_start && y))
			break ;
	}
	return (1);
}

t_octant	*ft_init_octant(int octant_n, t_octant *octant)
{
	octant->nbr = octant_n;
	if (octant_n == 1 || octant_n == 2 || octant_n == 3 || octant_n == 8)
		octant->i = 1;
	if (octant_n == 4 || octant_n == 5 || octant_n == 6 || octant_n == 7)
		octant->i = -1;
	if (octant_n == 1 || octant_n == 2 || octant_n == 4 || octant_n == 7)
		octant->j = 1;
	if (octant_n == 3 || octant_n == 5 || octant_n == 6 || octant_n == 8)
		octant->j = -1;
	return (octant);
}

int	ft_trace_octant_v(t_trace_params trace_params, t_octant octant, \
int color)
{
	trace_params.error = trace_params.delta_y;
	trace_params.delta_y = trace_params.error * 2;
	trace_params.delta_x = trace_params.delta_x * 2;
	while (1)
	{
		mlx_pixel_put(trace_params.mlx_ptr, trace_params.win_ptr, \
		trace_params.x_start, trace_params.y_start, color);
		trace_params.y_start = trace_params.y_start + octant.i;
		if (trace_params.y_start == trace_params.y_end)
			break ;
		if (octant.nbr == 2 || octant.nbr == 6)
			trace_params.error -= trace_params.delta_x;
		if (octant.nbr == 3 || octant.nbr == 7)
			trace_params.error += trace_params.delta_x;
		if ((octant.nbr == 2 && trace_params.error < 0) || (octant.nbr == 3 && \
		trace_params.error <= 0) || (octant.nbr == 7 && trace_params.error > 0) \
		|| (octant.nbr == 6 && trace_params.error >= 0))
		{
			trace_params.x_start = trace_params.x_start + octant.j;
			trace_params.error += trace_params.delta_y;
		}
	}
	return (1);
}

int	ft_trace_octant_h(t_trace_params trace_params, t_octant octant, \
int color)
{
	trace_params.error = trace_params.delta_x;
	trace_params.delta_x = trace_params.error * 2;
	trace_params.delta_y = trace_params.delta_y * 2;
	while (1)
	{
		mlx_pixel_put(trace_params.mlx_ptr, trace_params.win_ptr, \
		trace_params.x_start, trace_params.y_start, color);
		trace_params.x_start = trace_params.x_start + octant.i;
		if (trace_params.x_start == trace_params.x_end)
			break ;
		if (octant.nbr == 1 || octant.nbr == 5)
			trace_params.error -= trace_params.delta_y;
		if (octant.nbr == 4 || octant.nbr == 8)
			trace_params.error += trace_params.delta_y;
		if (((octant.nbr == 1 || octant.nbr == 8) && trace_params.error < 0) \
		|| ((octant.nbr == 4 || octant.nbr == 5) && trace_params.error >= 0))
		{
			trace_params.y_start = trace_params.y_start + octant.j;
			trace_params.error += trace_params.delta_x;
		}
	}
	return (1);
}

int	ft_trace_quadrant(t_trace_params trace_params, int quadrant)
{
	t_octant	octant;

	if (quadrant == 1 && trace_params.delta_x >= trace_params.delta_y)
		ft_trace_octant_h(trace_params, *ft_init_octant(1, &octant), GREEN);
	else if (quadrant == 1)
		ft_trace_octant_v(trace_params, *ft_init_octant(2, &octant), ORANGE);
	else if (quadrant == 2 && (-trace_params.delta_x) >= trace_params.delta_y)
		ft_trace_octant_h(trace_params, *ft_init_octant(4, &octant), LIME);
	else if (quadrant == 2)
		ft_trace_octant_v(trace_params, *ft_init_octant(3, &octant), PURPLE);
	else if (quadrant == 3 && trace_params.delta_x <= trace_params.delta_y)
		ft_trace_octant_h(trace_params, *ft_init_octant(5, &octant), CYAN);
	else if (quadrant == 3)
		ft_trace_octant_v(trace_params, *ft_init_octant(6, &octant), GRAY);
	else if (quadrant == 4 && trace_params.delta_x >= -trace_params.delta_y)
		ft_trace_octant_h(trace_params, *ft_init_octant(8, &octant), PINK);
	else if (quadrant == 4)
		ft_trace_octant_v(trace_params, *ft_init_octant(7, &octant), YELLOW);
	return (1);
}
