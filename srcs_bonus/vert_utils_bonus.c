/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:54:30 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:22:23 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

float	find_vert_ystep(t_info *info, int ray_id, float angle)
{
	float	ystep;

	ystep = info->tile_size * tan(angle);
	if (info->rays[ray_id].facing_up && ystep > 0)
		ystep *= -1;
	if (info->rays[ray_id].facing_down && ystep < 0)
		ystep *= -1;
	return (ystep);
}

float	find_vert_xstep(t_info *info, int ray_id)
{
	float	xstep;

	xstep = info->tile_size;
	if (info->rays[ray_id].facing_left)
		xstep *= -1;
	return (xstep);
}

float	find_vert_yintercept(t_info *info, float angle, float xintercept)
{
	float	yintercept;

	yintercept = info->player->y + (xintercept - info->player->x) * tan(angle);
	return (yintercept);
}

float	find_vert_xintercept(t_info *info, int ray_id)
{
	float	xintercept;

	xintercept = floor(info->player->x / info->tile_size) * info->tile_size;
	if (info->rays[ray_id].facing_right)
		xintercept += info->tile_size;
	return (xintercept);
}
