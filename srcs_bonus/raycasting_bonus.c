/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:54:43 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 17:06:07 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	find_facing(t_info *info, float ray_angle, int ray_id)
{
	info->rays[ray_id].facing_down = (ray_angle > 0 && ray_angle < PI);
	info->rays[ray_id].facing_up = !info->rays[ray_id].facing_down;
	info->rays[ray_id].facing_right = (ray_angle < 0.5 * PI || \
		ray_angle > 1.5 * PI);
	info->rays[ray_id].facing_left = !info->rays[ray_id].facing_right;
}

void	find_vert(t_info *info, float ray_angle, int ray_id)
{
	struct s_helper	r;

	r.xintercept = find_vert_xintercept(info, ray_id);
	r.yintercept = find_vert_yintercept(info, ray_angle, r.xintercept);
	r.xstep = find_vert_xstep(info, ray_id);
	r.ystep = find_vert_ystep(info, ray_id, ray_angle);
	while (is_inside_map(info, r.xintercept, r.yintercept))
	{
		r.x_check = r.xintercept;
		r.y_check = r.yintercept;
		if (info->rays[ray_id].facing_left)
			r.x_check += -1;
		if (is_wall(info, r.x_check, r.y_check))
		{
			info->rays[ray_id].vert_hit_x = r.xintercept;
			info->rays[ray_id].vert_hit_y = r.yintercept;
			info->rays[ray_id].vert_wall_content = \
				map_content_at(info, r.x_check, r.y_check);
			info->rays[ray_id].found_vert_wall_hit = true;
			break ;
		}
		r.xintercept += r.xstep;
		r.yintercept += r.ystep;
	}
}

void	find_horz(t_info *info, float ray_angle, int ray_id)
{
	struct s_helper	r;

	r.yintercept = find_horz_yintercept(info, ray_id);
	r.xintercept = find_horz_xintercept(info, ray_angle, r.yintercept);
	r.ystep = find_horz_ystep(info, ray_id);
	r.xstep = find_horz_xstep(info, ray_id, ray_angle);
	while (is_inside_map(info, r.xintercept, r.yintercept))
	{
		r.x_check = r.xintercept;
		r.y_check = r.yintercept;
		if (info->rays[ray_id].facing_up)
			r.y_check += -1;
		if (is_wall(info, r.x_check, r.y_check))
		{
			info->rays[ray_id].horz_hit_x = r.xintercept;
			info->rays[ray_id].horz_hit_y = r.yintercept;
			info->rays[ray_id].horz_wall_content = \
				map_content_at(info, r.x_check, r.y_check);
			info->rays[ray_id].found_horz_wall_hit = true;
			break ;
		}
		r.xintercept += r.xstep;
		r.yintercept += r.ystep;
	}
}

void	cast_ray(t_info *info, float ray_angle, int ray_id)
{
	float	horz_dist;
	float	vert_dist;

	find_facing(info, ray_angle, ray_id);
	find_horz(info, ray_angle, ray_id);
	find_vert(info, ray_angle, ray_id);
	if (info->rays[ray_id].found_horz_wall_hit)
	{
		horz_dist = distance_between_points(info->player->x, info->player->y, \
		info->rays[ray_id].horz_hit_x, info->rays[ray_id].horz_hit_y);
	}
	else
		horz_dist = FLT_MAX;
	if (info->rays[ray_id].found_vert_wall_hit)
	{
		vert_dist = distance_between_points(info->player->x, info->player->y, \
		info->rays[ray_id].vert_hit_x, info->rays[ray_id].vert_hit_y);
	}
	else
		vert_dist = FLT_MAX;
	if (vert_dist < horz_dist)
		set_ray_data(info, ray_id, vert_dist, 1);
	else
		set_ray_data(info, ray_id, horz_dist, 0);
	info->rays[ray_id].ray_angle = ray_angle;
}

void	cast_all_rays(t_info *info)
{
	int		i;
	float	ray_angle;

	i = -1;
	ft_memset(info->rays, 0, info->num_rays * sizeof(t_ray));
	while (++i < info->num_rays)
	{
		ray_angle = info->player->rotation_angle + \
			atan((i - info->num_rays / 2) / info->dist_proj_plane);
		normalize_angle(&ray_angle);
		cast_ray(info, ray_angle, i);
	}
}
