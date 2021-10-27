/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:11:21 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:24:29 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	define_pixel(t_info *info, int x, int y, unsigned char color[4])
{
	int	index;

	if (y < 0 || y >= info->height || x < 0 || x >= info->width)
		return ;
	index = y * 4 * info->width + x * 4;
	info->data[index] = color[2];
	info->data[index + 1] = color[1];
	info->data[index + 2] = color[0];
	info->data[index + 3] = color[3];
}

int	find_side_lenght(int delta_x, int delta_y)
{
	int	side_lenght;

	if (abs(delta_x) >= abs(delta_y))
		side_lenght = abs(delta_x);
	else
		side_lenght = abs(delta_y);
	return (side_lenght);
}

void	draw_line(t_info *info, int i, float x0, float y0)
{
	int				delta_x;
	int				delta_y;
	unsigned char	color[4];
	float			x_inc;
	float			y_inc;

	delta_x = ((info->rays[i].wall_hit_x * MINIMAP_SCALE_FACTOR) - x0);
	delta_y = ((info->rays[i].wall_hit_y * MINIMAP_SCALE_FACTOR) - y0);
	i = find_side_lenght(delta_x, delta_y);
	x_inc = delta_x / (float)i;
	y_inc = delta_y / (float)i;
	set_color(color, 255, 0, 0);
	i += 1;
	while (--i >= 0)
	{
		define_pixel(info, round(x0), round(y0), color);
		x0 += x_inc;
		y0 += y_inc;
	}
}

void	draw_rect(t_info *info, t_rect rect, unsigned char color[4])
{
	int	y;
	int	x;

	y = rect.y - 1;
	while (++y <= rect.y + rect.height)
	{
		x = rect.x - 1;
		while (++x <= rect.x + rect.width)
			define_pixel(info, x, y, color);
	}
}

void	display_background(t_info *info)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = info->width;
	rect.height = info->height / 2;
	draw_rect(info, rect, info->ceil);
	rect.y = info->height / 2;
	draw_rect(info, rect, info->floor);
}
