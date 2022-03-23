/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:19:25 by pcottet           #+#    #+#             */
/*   Updated: 2022/02/01 06:56:01 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "colors_and_keys.h"
# define ERROR_FILE 4
# define ERROR_FD 5
# define ERROR_MAP 6
# define ERROR_MALLOC 7
# define WIN_HEIGHT 1000
# define WIN_WIDTH  1200
# define START  's'
# define END  'e'

typedef struct s_mlx_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		draw_x;
	int		draw_y;
	int		fd;
}	t_mlx_params;

typedef struct s_matrix_coor
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_matrix_coor;

typedef struct s_map
{
	t_matrix_coor	**matrix;
	int				row;
	int				col;
}	t_map;

typedef struct s_octant
{
	int	nbr;
	int	i;
	int	j;
}	t_octant;

typedef struct s_trace_params
{
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
	int			z_start;
	int			z_end;
	int			z_plus;
	int			delta_x;
	int			delta_y;
	int			error;
	void		*mlx_ptr;
	void		*win_ptr;
	int			fd;
	int			px_space;
	int			color;
	float		angle;
	float		angle_rotation;
	float		zoom;
	int			move_y;
	int			move_x;
	int			move_z;
	int			arrow_mode;
	int			i;
	int			j;
	t_map		*map;
}	t_trace_params;

void		ft_exit(t_trace_params *trace_params);
void		ft_exit_error(int error_code);
void		ft_free_lst(t_list *lst);
int			ft_str_isdigit(char *str);
void		ft_checkmap(char *file);
int			deal_key(int key, t_trace_params *trace_params);
int			ft_hex_to_i(char *hex, int hex_size);
void		ft_matrix_draw(t_map *map, t_trace_params trace_params);
int			ft_height_color(t_matrix_coor *matrix_coor, int x, \
			int y, char *height_color);
void		ft_build_matrix(t_list *map_coor, t_trace_params *trace_params);
void		ft_free_exit(t_trace_params *trace_params, \
			void (*f)(void *), void *ptr);
t_list		*ft_map_lst(t_trace_params *trace_params);
void		ft_prepare_matrix(t_trace_params *trace_params, t_list *map_coor);
int			ft_matrix_loop(t_list *map_coor, t_trace_params *trace_params, \
			int i, int y);
void		ft_get_map(t_trace_params *trace_params);
int			ft_px_btw(t_trace_params *trace_params);
int			ft_trace_vector(t_trace_params trace_params);
void		ft_view(t_trace_params *trace_params);
int			ft_trace_no_delta(t_trace_params trace_params);
int			ft_trace_delta(t_trace_params trace_params);
int			ft_trace_quadrant(t_trace_params trace_params, int quadrant);
int			ft_trace_octant_h(t_trace_params trace_params, \
			t_octant octant, int color);
int			ft_trace_octant_v(t_trace_params trace_params, \
			t_octant octant, int color);
t_octant	*ft_init_octant(int octant_n, t_octant *octant);
int			ft_trace_xy_vector(t_trace_params trace_params, int x, int y);
void		ft_rotate_view(t_trace_params *trace_params);
void		ft_iso_view(t_trace_params *trace_params);
int			ft_init_params(t_trace_params *trace_params);
void		ft_arrow_mode(int key, t_trace_params *trace_params);
#endif
