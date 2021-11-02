/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:39:07 by cdapurif          #+#    #+#             */
/*   Updated: 2021/11/02 15:07:24 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

char	map_content_at(t_info *info, float x, float y)
{
	int	grid_x;
	int	grid_y;

	if (x < 0 || x >= info->x_limit || y < 0 || y >= info->y_limit)
		return ('1');
	grid_x = floor(x / info->tile_size);
	grid_y = floor(y / info->tile_size);
	return (info->map[grid_y][grid_x]);
}

void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

t_ray	*init_rays(t_info *info)
{
	t_ray	*rays;

	rays = ft_calloc(info->num_rays, sizeof(t_ray));
	if (!rays)
		parsing_error(NULL, info, "problem initializing rays struct\n");
	return (rays);
}

void	clear_image(t_info *info)
{
	ft_memset((void *)info->data, 0, info->width * info->height * 4);
}
