/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 23:42:08 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:25:42 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_texture	*find_good_texture(t_info *info, int x)
{
	if (info->rays[x].was_hit_vertical)
	{
		if (info->player->x > info->rays[x].wall_hit_x)
			return (info->ea_texture);
		else
			return (info->we_texture);
	}
	else
	{
		if (info->player->y < info->rays[x].wall_hit_y)
			return (info->no_texture);
		else
			return (info->so_texture);
	}
	return (NULL);
}

void	place_texture(t_info *info, struct s_text_info data, int wall_height, \
						int x)
{
	int			y;
	int			cpt;
	int			distance_from_top;
	t_texture	*text;

	y = data.top_pixel - 1;
	text = data.text;
	while (++y < data.bottom_pixel)
	{
		distance_from_top = y + (wall_height / 2) - (info->height / 2);
		data.text_offset_y = distance_from_top * \
			((float)data.text->height / wall_height);
		cpt = -1;
		while (++cpt < 4)
		{
			info->data[(info->width * 4 * y) + (4 * x) + cpt] = \
				text->data[(text->width * 4 * data.text_offset_y) + \
				(data.text_offset_x * 4) + cpt];
		}
	}
}

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (texture)
	{
		if (texture->texture)
			mlx_destroy_image(mlx_ptr, texture->texture);
		free(texture);
	}
}

t_texture	*get_texture(char *file, t_info *info)
{
	int			i;
	int			data[3];
	t_texture	*img;

	img = ft_calloc(1, sizeof(t_texture));
	if (!img)
		parsing_error(file, info);
	i = 2;
	while (file[i] && ft_iswhitespace(file[i]))
		i++;
	img->texture = mlx_xpm_file_to_image(info->mlx_ptr, file + i, \
	&img->width, &img->height);
	if (img->texture)
	{
		data[0] = 0;
		data[1] = 0;
		data[2] = 0;
		img->data = mlx_get_data_addr(img->texture, &data[0], &data[1], \
		&data[2]);
	}
	return (img);
}
