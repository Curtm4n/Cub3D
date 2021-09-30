/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:22:00 by curtman           #+#    #+#             */
/*   Updated: 2021/09/30 20:47:15 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_info(t_info *info)
{
	if (info->map_ptr)
		ft_lstclear(&(info->map_ptr), &free);
	if (info->mlx_ptr)
	{
		if (info->window_ptr)
			mlx_destroy_window(info->mlx_ptr, info->window_ptr);
		if (info->image)
			mlx_destroy_image(info->mlx_ptr, info->image);
		free_texture(info->mlx_ptr, info->no_texture);
		free_texture(info->mlx_ptr, info->so_texture);
		free_texture(info->mlx_ptr, info->ea_texture);
		free_texture(info->mlx_ptr, info->we_texture);
		mlx_destroy_display(info->mlx_ptr);
		free(info->mlx_ptr);
	}
	free(info);
}

void	parsing_error(char *line, t_info *info)
{
	if (line)
		free(line);
	free_info(info);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_parsing(t_info *info)
{
	if (WIDTH <= 0 || HEIGHT <= 0)
		parsing_error(NULL, info);
	if (!info->no_texture->texture || !info->so_texture->texture || \
		!info->we_texture->texture || !info->ea_texture->texture)
		parsing_error(NULL, info);
	if (!info->map_ptr)
		parsing_error(NULL, info);
	check_map(info);
}

void	handle_info_line(char *line, t_info *info)
{
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		parsing_text(line, info);
	if (*line == 'F' || *line == 'C')
		parsing_color(line, info);
}

void	handle_map_line(char *line, t_info *info)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(line));
	if (!new || !(new->content))
		parsing_error(line, info);
	ft_lstadd_back(&(info->map_ptr), new);
}
