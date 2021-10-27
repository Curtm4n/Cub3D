/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:42:40 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/05 14:14:53 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	find_horz_yintercept(t_info *info, int ray_id)
{
	float	yintercept;

	yintercept = floor(info->player->y / info->tile_size) * info->tile_size;
	if (info->rays[ray_id].facing_down)
		yintercept += info->tile_size;
	return (yintercept);
}

float	find_horz_xintercept(t_info *info, float angle, float yintercept)
{
	float	xintercept;

	xintercept = info->player->x + (yintercept - info->player->y) / tan(angle);
	return (xintercept);
}

float	find_horz_ystep(t_info *info, int ray_id)
{
	float	ystep;

	ystep = info->tile_size;
	if (info->rays[ray_id].facing_up)
		ystep *= -1;
	return (ystep);
}

float	find_horz_xstep(t_info *info, int ray_id, float angle)
{
	float	xstep;

	xstep = info->tile_size / tan(angle);
	if (info->rays[ray_id].facing_left && xstep > 0)
		xstep *= -1;
	if (info->rays[ray_id].facing_right && xstep < 0)
		xstep *= -1;
	return (xstep);
}
