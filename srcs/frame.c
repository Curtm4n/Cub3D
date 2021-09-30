/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:19:26 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/01 00:15:37 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update(t_info *info)
{
	static int	x = 0;
	static int	y = 0;

	x += 1;
	y += 1;
	clear_image(info);
	display_background(info);
	rect(info, x, y);
}
