/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:41:02 by cdapurif          #+#    #+#             */
/*   Updated: 2021/11/02 14:26:36 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned char	get_color(char *line, t_info *info, int i)
{
	int	color;

	color = ft_atoi(line + i);
	if (color < 0 || color > 255)
		parsing_error(line, info, "color values must be 0-255\n");
	return (color);
}
