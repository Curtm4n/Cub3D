/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:05:32 by curtman           #+#    #+#             */
/*   Updated: 2021/08/05 16:41:32 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_info *info)
{
	int		line;
	int		pos_index;
	t_list	*ptr;

	line = -1;
	pos_index = -1;
	if (ft_lstsize(info->map_ptr) < 3)
		parsing_error(NULL, info);
	ptr = info->map_ptr;
	while (ptr)
	{
		if (pos_index == -1)
			++line;
		if (!ft_is_good_mapchar((char *)ptr->content))
			parsing_error(NULL, info);
		pos_index = find_pos((char *)ptr->content, info, pos_index);
		ptr = ptr->next;
	}
	if (pos_index == -1)
		parsing_error(NULL, info);
	ff_check(info, pos_index, line);
}

void	parsing_res(char *line, t_info *info)
{
	int	i;

	i = 1;
	while (line[i] && (ft_iswhitespace(line[i]) || \
		(line[i] >= '0' && line[i] <= '9')))
		i++;
	if (line[i] != '\0')
		parsing_error(line, info);
	info->width = fmin(ft_atoi(line + 1), WIDTH_MAX);
	i = 1;
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	info->height = fmin(ft_atoi(line + i), HEIGHT_MAX);
}

void	parsing_text(char *line, t_info *info)
{
	unsigned char	begin[2];

	begin[0] = line[0];
	begin[1] = line[1];
	if (line[1] == '\0')
		parsing_error(line, info);
	if (begin[0] == 'N' && begin[1] == 'O')
		info->no_texture = get_texture(line, info);
	else if (begin[0] == 'W' && begin[1] == 'E')
		info->we_texture = get_texture(line, info);
	else if (begin[0] == 'E' && begin[1] == 'A')
		info->ea_texture = get_texture(line, info);
	else if (begin[0] == 'S' && begin[1] == 'O')
		info->so_texture = get_texture(line, info);
	else if (begin[0] == 'S' && ft_iswhitespace(begin[1]))
		info->sprite_texture = get_texture(line, info);
	else
		parsing_error(line, info);
}

void	set_color(unsigned char color[3], unsigned char r, unsigned char g,
unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void	parsing_color(char *line, t_info *info)
{
	int				i;
	unsigned char	color[3];

	i = 1;
	if (line[i] == '\0')
		parsing_error(line, info);
	while (ft_iswhitespace(line[i]))
		i++;
	color[0] = fmin(ft_atoi(line + i), 255);
	while (ft_isdigit(line[i]) || ft_iswhitespace(line[i]))
		i++;
	if (line[i] != ',')
		parsing_error(line, info);
	color[1] = fmin(ft_atoi(line + (++i)), 255);
	while (ft_isdigit(line[i]) || ft_iswhitespace(line[i]))
		i++;
	if (line[i] != ',')
		parsing_error(line, info);
	color[2] = fmin(ft_atoi(line + (++i)), 255);
	if (*line == 'C')
		set_color(info->ceil, color[0], color[1], color[2]);
	if (*line == 'F')
		set_color(info->floor, color[0], color[1], color[2]);
}
