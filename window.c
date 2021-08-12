/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:39:09 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:45:33 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_key(int key, void *param)
{
	(void)param;
	if (key == 65307)
	{
		free_info((t_info *)param);
		exit(0);
	}
	printf("%d\n", key);
	return (0);
}

int	print_mouse_pos(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	printf("mouse cursor is on : %d, %d\n", x, y);
	return (0);
}

void	ft_display(t_info *info)
{
	info->window_ptr = mlx_new_window(info->mlx_tmp_ptr, info->width, \
		info->height, "Hello world!");
	if (!info->window_ptr)
		return ;
	mlx_put_image_to_window(info->mlx_tmp_ptr, info->window_ptr,
		info->no_texture->texture, info->width / 2, info->height / 2);
	mlx_mouse_hook(info->window_ptr, print_mouse_pos, NULL);
	mlx_key_hook(info->window_ptr, print_key, info);
	mlx_loop(info->mlx_tmp_ptr);
}
