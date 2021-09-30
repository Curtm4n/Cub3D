/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 23:42:08 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/08 15:46:56 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
