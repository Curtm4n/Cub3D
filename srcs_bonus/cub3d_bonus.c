/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:38:53 by curtman           #+#    #+#             */
/*   Updated: 2021/10/27 16:25:04 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_cub3d(char **av)
{
	t_info	*info;

	info = ft_parsing(av[1]);
	ft_launch_game(info);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_cub3d(av);
	else
		ft_putstr_fd("Error\nusage : ./cub3D *.cub\n", 2);
	return (0);
}
