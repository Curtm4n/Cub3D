/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:39:09 by cdapurif          #+#    #+#             */
/*   Updated: 2021/11/02 14:23:15 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_res(t_info *info)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (info->map[++i])
		max = (int)fmax(max, ft_strlen(info->map[i]));
	info->map_num_rows = i;
	info->map_num_cols = max;
	info->width = WIDTH;
	info->height = HEIGHT;
	info->tile_size = 64;
	info->x_limit = info->map_num_cols * info->tile_size;
	info->y_limit = info->map_num_rows * info->tile_size;
}

t_player	*init_player(t_info *info)
{
	t_player	*p;

	p = ft_calloc(1, sizeof(t_player));
	if (!p)
		parsing_error(NULL, info, "problem allocating player struct\n");
	p->x = info->px * info->tile_size + (info->tile_size / 2);
	p->y = info->py * info->tile_size + (info->tile_size / 2);
	p->width = 5;
	p->height = 5;
	p->turn_direction = 0;
	p->walk_direction = 0;
	p->side_direction = 0;
	p->walk_speed = 11.5;
	p->turn_speed = 4 * (PI / 180);
	if (info->orientation == 'N')
		p->rotation_angle = 1.5 * PI;
	else if (info->orientation == 'E')
		p->rotation_angle = 0;
	else if (info->orientation == 'S')
		p->rotation_angle = PI / 2;
	else if (info->orientation == 'W')
		p->rotation_angle = PI;
	return (p);
}

void	setup(t_info *info)
{
	info->map = create_map_matrix(info);
	set_res(info);
	info->fov = 60 * (PI / 180);
	info->num_rays = info->width;
	info->dist_proj_plane = (info->width / 2) / tan(info->fov / 2);
	info->player = init_player(info);
	info->rays = init_rays(info);
}

void	init_window(t_info *info)
{
	int	config[3];
	int	width;
	int	height;

	width = info->width;
	height = info->height;
	config[0] = 32;
	config[1] = info->width * 4;
	config[2] = 0;
	info->window_ptr = mlx_new_window(info->mlx_ptr, width, height, "Cub3D");
	info->image = mlx_new_image(info->mlx_ptr, width, height);
	info->data = mlx_get_data_addr(info->image, &config[0], &config[1], \
		&config[2]);
	if (!info->window_ptr || !info->image || !info->data)
		parsing_error(NULL, info, "problem initializing some mlx part\n");
}

void	ft_launch_game(t_info *info)
{
	setup(info);
	init_window(info);
	mlx_hook(info->window_ptr, 2, 1L << 0, key_pressed, info);
	mlx_hook(info->window_ptr, 3, 1L << 1, key_released, info);
	mlx_hook(info->window_ptr, 33, 1L << 17, close_game, info);
	mlx_hook(info->window_ptr, Expose, ExposureMask, minimize_window, info);
	mlx_loop_hook(info->mlx_ptr, loop_hook, info);
	mlx_loop(info->mlx_ptr);
}
