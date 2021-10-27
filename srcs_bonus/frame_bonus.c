/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:19:26 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:24:13 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	render(t_info *info)
{
	display_background(info);
	generate_3d_proj(info);
	render_map(info);
	render_rays(info);
	render_player(info);
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->image, 0, 0);
}

void	update(t_info *info)
{
	clear_image(info);
	move_player(info);
	cast_all_rays(info);
}
