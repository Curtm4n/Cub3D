/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:11:21 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/01 00:14:59 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	define_pixel(t_info *info, int column, int line, unsigned char color[4])
{
	int	index;

	if (line >= HEIGHT || column >= WIDTH)
		return ;
	index = line * 4 * WIDTH + column * 4;
	info->data[index] = color[2];
	info->data[index + 1] = color[1];
	info->data[index + 2] = color[0];
	info->data[index + 3] = color[3];
}

void	draw_rect(t_info *info, t_rect rect, unsigned char color[4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < rect.height)
	{
		j = -1;
		while (++j < rect.width)
			define_pixel(info, rect.x + j, rect.y + i, color);
	}
}

void	rect(t_info *info, int x, int y)
{
	t_rect			rect;
	unsigned char	color[4];

	set_color(color, 255, 255, 0);
	rect.x = x;
	rect.y = y;
	rect.width = 20;
	rect.height = 20;
	draw_rect(info, rect, color);
}

void	display_background(t_info *info)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = WIDTH;
	rect.height = HEIGHT / 2;
	draw_rect(info, rect, info->ceil);
	rect.y = HEIGHT / 2;
	draw_rect(info, rect, info->floor);
}
