/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:27:26 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:23:07 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_ray_data(t_info *info, int id, float dist, int vertical)
{
	if (vertical)
	{
		info->rays[id].distance = dist;
		info->rays[id].wall_hit_x = info->rays[id].vert_hit_x;
		info->rays[id].wall_hit_y = info->rays[id].vert_hit_y;
		info->rays[id].hit_content = info->rays[id].vert_wall_content;
		info->rays[id].was_hit_vertical = true;
	}
	if (!vertical)
	{
		info->rays[id].distance = dist;
		info->rays[id].wall_hit_x = info->rays[id].horz_hit_x;
		info->rays[id].wall_hit_y = info->rays[id].horz_hit_y;
		info->rays[id].hit_content = info->rays[id].horz_wall_content;
		info->rays[id].was_hit_vertical = false;
	}
}
