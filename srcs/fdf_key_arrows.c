/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_arrows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:34:07 by pcottet           #+#    #+#             */
/*   Updated: 2022/02/01 13:34:18 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_arrow_rota(int key, t_trace_params *trace_params)
{
	if (key == ARROW_LEFT)
		trace_params->angle_rotation += 0.02;
	if (key == ARROW_RIGHT)
		trace_params->angle_rotation -= 0.02;
	if (key == ARROW_UP)
		trace_params->angle -= 0.02;
	if (key == ARROW_DOWN)
		trace_params->angle += 0.02;
}

void	ft_arrow_move(int key, t_trace_params *trace_params)
{
	if (key == ARROW_LEFT)
		trace_params->move_x -= 100;
	if (key == ARROW_RIGHT)
		trace_params->move_x += 100;
	if (key == ARROW_UP)
		trace_params->move_y -= 100;
	if (key == ARROW_DOWN)
		trace_params->move_y += 100;
}

void	ft_arrow_zoom(int key, t_trace_params *trace_params)
{
	if (key == ARROW_LEFT)
	{
		trace_params->move_x -= 100;
		trace_params->move_y -= 100;
	}
	if (key == ARROW_RIGHT)
	{
		trace_params->move_x += 100;
		trace_params->move_y += 100;
	}
	if (key == ARROW_UP)
	{
		trace_params->z_plus += 1;
	}
	if (key == ARROW_DOWN)
		trace_params->z_plus -= 1;
}

void	ft_arrow_mode(int key, t_trace_params *trace_params)
{
	if (trace_params->arrow_mode == MODE_ROTA)
		ft_arrow_rota(key, trace_params);
	if (trace_params->arrow_mode == MODE_MOVE)
		ft_arrow_move(key, trace_params);
	if (trace_params->arrow_mode == MODE_ZOOM)
		ft_arrow_zoom(key, trace_params);
}
