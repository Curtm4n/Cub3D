/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:12:15 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/21 21:50:11 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_inside_map(t_info *info, float x, float y)
{
	return (x >= 0 && x <= info->x_limit && y >= 0 && y <= info->y_limit);
}

int	find_text_offset_x(t_info *info, t_texture *text, int x)
{
	float	ratio;
	int		text_offset_x;

	ratio = (float)text->width / info->tile_size;
	if (info->rays[x].was_hit_vertical)
		text_offset_x = (int)info->rays[x].wall_hit_y % info->tile_size * ratio;
	else
		text_offset_x = (int)info->rays[x].wall_hit_x % info->tile_size * ratio;
	return (text_offset_x);
}

int	find_bottom_pixel(t_info *info, int wall_height)
{
	int	bottom_pixel;

	bottom_pixel = (info->height / 2) + (wall_height / 2);
	if (bottom_pixel > info->height)
		bottom_pixel = info->height;
	return (bottom_pixel);
}

int	find_top_pixel(t_info *info, int wall_height)
{
	int	top_pixel;

	top_pixel = (info->height / 2) - (wall_height / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	return (top_pixel);
}
