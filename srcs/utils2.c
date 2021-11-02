/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:10:49 by cdapurif          #+#    #+#             */
/*   Updated: 2021/11/02 14:25:37 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_wall_height(t_info *info, int x)
{
	float	proj_wall_height;

	info->rays[x].distance *= \
		cos(info->rays[x].ray_angle - info->player->rotation_angle);
	proj_wall_height = (info->tile_size / info->rays[x].distance) * \
		info->dist_proj_plane;
	return ((int)proj_wall_height);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}

char	**get_lines(t_info *info, char **map, int line_lenght)
{
	char	*str;
	t_list	*ptr;
	int		i;

	ptr = info->map_ptr;
	i = 0;
	while (ptr)
	{
		str = malloc(sizeof(char) * (line_lenght + 1));
		if (!str)
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			parsing_error(NULL, info, "problem allocating the map\n");
		}
		ft_memset(str, 32, line_lenght);
		str[line_lenght] = '\0';
		map[i] = ft_strcpy(str, (char *)ptr->content);
		ptr = ptr->next;
		i++;
	}
	return (map);
}

char	**create_map_matrix(t_info *info)
{
	char	**map;
	int		num_line;
	int		line_lenght;

	num_line = ft_lstsize(info->map_ptr);
	map = malloc(sizeof(char *) * (num_line + 1));
	if (!map)
		parsing_error(NULL, info, "problem allocating the map\n");
	map[num_line] = 0;
	line_lenght = find_max(info);
	map = get_lines(info, map, line_lenght);
	return (map);
}
