/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:52:14 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/28 17:36:16 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	find_max(t_info *info)
{
	t_list	*ptr;
	int		max;

	ptr = info->map_ptr;
	max = 0;
	while (ptr)
	{
		max = (int)fmax(max, ft_strlen((char *)ptr->content));
		ptr = ptr->next;
	}
	return (max);
}

void	correct_map_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '_')
				map[i][j] = '0';
		}
	}
}

char	change_char(char c)
{
	if (c == '0')
		return ('_');
	return (c);
}

int	correct_char(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

void	check_borders(t_info *info, char **map, int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0 || x + 1 == ft_strlen(map[y]) || map[y + 1] == 0)
	{
		free(map);
		parsing_error(NULL, info);
	}
	if (map[y][x - 1] == 32 || map[y][x + 1] == 32)
	{
		free(map);
		parsing_error(NULL, info);
	}
	if (x < ft_strlen(map[y - 1]) && map[y - 1][x] == 32)
	{
		free(map);
		parsing_error(NULL, info);
	}
	if (x < ft_strlen(map[y + 1]) && map[y + 1][x] == 32)
	{
		free(map);
		parsing_error(NULL, info);
	}
	check_limits(info, map, x, y);
}
