/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:52:14 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:44:20 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (map[i][j] == '|')
				map[i][j] = '2';
		}
	}
}

char	change_char(char c)
{
	if (c == '0')
		return ('_');
	if (c == '2')
		return ('|');
	return (c);
}

int	correct_char(char c)
{
	if (c == '0' || c == '2')
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
}
