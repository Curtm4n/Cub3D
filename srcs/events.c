/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:37:10 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/01 00:16:44 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(void *info)
{
	quit_game((t_info *)info);
	return (0);
}

int	minimize_window(void *info)
{
	(void)info;
	printf("The window has been minimized, you should re-display the map\n");
	return (0);
}

int	loop_hook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	update(info);
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->image, 0, 0);
	mlx_do_sync(info->mlx_ptr);
	return (0);
}

int	my_key_hook(int key, void *param)
{
	if (key == 65307)
		quit_game((t_info *)param);
	printf("%d\n", key);
	return (0);
}
