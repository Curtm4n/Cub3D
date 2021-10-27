/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:09:58 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:22:05 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	is_wall(t_info *info, float x, float y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= info->x_limit || y < 0 || y >= info->y_limit)
		return (true);
	map_x = floor(x / info->tile_size);
	map_y = floor(y / info->tile_size);
	return (info->map[map_y][map_x] == '1');
}

void	move_side(t_info *info, t_player *p, float move_step)
{
	float	new_player_x;
	float	new_player_y;

	new_player_x = p->x + sin(p->rotation_angle) * move_step;
	new_player_y = p->y - cos(p->rotation_angle) * move_step;
	if (!is_wall(info, new_player_x, new_player_y))
	{
		p->x = new_player_x;
		p->y = new_player_y;
	}
}

void	move_walk(t_info *info, t_player *p, float move_step)
{
	float	new_player_x;
	float	new_player_y;

	new_player_x = p->x + cos(p->rotation_angle) * move_step;
	new_player_y = p->y + sin(p->rotation_angle) * move_step;
	if (!is_wall(info, new_player_x, new_player_y))
	{
		p->x = new_player_x;
		p->y = new_player_y;
	}
}

void	move_player(t_info *info)
{
	t_player	*p;
	float		move_step;

	p = info->player;
	p->rotation_angle += p->turn_direction * p->turn_speed;
	normalize_angle(&(p->rotation_angle));
	move_step = p->walk_direction * p->walk_speed;
	if (p->walk_direction != 0)
		move_walk(info, p, move_step);
	move_step = p->side_direction * p->walk_speed;
	if (p->side_direction != 0)
		move_side(info, p, move_step);
}
