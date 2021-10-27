/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:52:03 by cdapurif          #+#    #+#             */
/*   Updated: 2021/10/27 16:25:31 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	quit_game(t_info *info)
{
	ft_putstr_fd("Goodbye ! hope we'll see you soon\n", 1);
	free_info(info);
	exit(EXIT_SUCCESS);
}
