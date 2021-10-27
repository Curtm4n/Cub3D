/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:37:10 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:24:38 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	close_game(void *info)
{
	quit_game((t_info *)info);
	return (0);
}

int	minimize_window(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	render(info);
	return (0);
}

int	loop_hook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	update(info);
	render(info);
	mlx_do_sync(info->mlx_ptr);
	return (0);
}

int	key_released(int key, void *param)
{
	t_player	*p;

	p = ((t_info *)param)->player;
	if (key == 'w')
		p->walk_direction = 0;
	if (key == 's')
		p->walk_direction = 0;
	if (key == 'd')
		p->side_direction = 0;
	if (key == 'a')
		p->side_direction = 0;
	if (key == 65363)
		p->turn_direction = 0;
	if (key == 65361)
		p->turn_direction = 0;
	return (0);
}

int	key_pressed(int key, void *param)
{
	t_player	*p;

	p = ((t_info *)param)->player;
	if (key == 65307)
		quit_game((t_info *)param);
	if (key == 'w')
		p->walk_direction = +1;
	if (key == 's')
		p->walk_direction = -1;
	if (key == 'd')
		p->side_direction = -1;
	if (key == 'a')
		p->side_direction = +1;
	if (key == 65363)
		p->turn_direction = +1;
	if (key == 65361)
		p->turn_direction = -1;
	return (0);
}
