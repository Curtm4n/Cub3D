/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:37:49 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/26 17:48:24 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_wall(t_info *info, int wall_height, int x)
{
	struct s_text_info	data;

	data.top_pixel = find_top_pixel(info, wall_height);
	data.bottom_pixel = find_bottom_pixel(info, wall_height);
	data.text = find_good_texture(info, x);
	if (!data.text)
		parsing_error(NULL, info);
	data.text_offset_x = find_text_offset_x(info, data.text, x);
	place_texture(info, data, wall_height, x);
}

void	generate_3d_proj(t_info *info)
{
	int	x;
	int	wall_height;

	x = -1;
	while (++x < info->num_rays)
	{
		wall_height = find_wall_height(info, x);
		set_wall(info, wall_height, x);
	}
}

void	render_player(t_info *info)
{
	t_rect			rect;
	unsigned char	color[4];

	rect.x = info->player->x * MINIMAP_SCALE_FACTOR;
	rect.y = info->player->y * MINIMAP_SCALE_FACTOR;
	rect.width = info->player->width * MINIMAP_SCALE_FACTOR;
	rect.height = info->player->height * MINIMAP_SCALE_FACTOR;
	set_color(color, 255, 255, 255);
	draw_rect(info, rect, color);
}

void	render_rays(t_info *info)
{
	int				i;

	i = 0;
	while (i < info->num_rays)
	{
		draw_line(info, i, (info->player->x * MINIMAP_SCALE_FACTOR), \
			(info->player->y * MINIMAP_SCALE_FACTOR));
		i += 30;
	}
}

void	render_map(t_info *info)
{
	int				i;
	int				j;
	unsigned char	color[4];
	t_rect			rect;

	i = -1;
	while (++i < info->map_num_rows)
	{
		j = -1;
		while (++j < info->map_num_cols)
		{
			if (info->map[i][j] == '1')
				set_color(color, 255, 255, 255);
			else if (info->map[i][j] == '0' || info->map[i][j] \
				== info->orientation)
				set_color(color, 0, 0, 0);
			else
				continue ;
			rect.x = (j * info->tile_size) * MINIMAP_SCALE_FACTOR;
			rect.y = (i * info->tile_size) * MINIMAP_SCALE_FACTOR;
			rect.width = info->tile_size * MINIMAP_SCALE_FACTOR;
			rect.height = info->tile_size * MINIMAP_SCALE_FACTOR;
			draw_rect(info, rect, color);
		}
	}
}
