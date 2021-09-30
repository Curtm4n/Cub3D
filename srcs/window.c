/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:39:09 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/01 00:16:27 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_info *info)
{
	int	config[3];

	config[0] = 32;
	config[1] = WIDTH * 4;
	config[2] = 0;
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	info->image = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->data = mlx_get_data_addr(info->image, &config[0], &config[1], \
		&config[2]);
	if (!info->window_ptr || !info->image || !info->data)
		parsing_error(NULL, info);
}

void	ft_launch_game(t_info *info)
{
	init_window(info);
	mlx_hook(info->window_ptr, 2, 1L << 0, my_key_hook, info);
	mlx_hook(info->window_ptr, 33, 1L << 17, close_game, info);
	mlx_hook(info->window_ptr, Expose, ExposureMask, minimize_window, info);
	mlx_loop_hook(info->mlx_ptr, loop_hook, info);
	mlx_loop(info->mlx_ptr);
}
