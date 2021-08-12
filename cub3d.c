/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:38:53 by curtman           #+#    #+#             */
/*   Updated: 2021/08/05 16:30:00 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cub3d(int ac, char **av)
{
	t_info	*info;

	if (ac == 3)
		ft_putstr_fd("Photo !\n", 1);
	info = ft_parsing(av[1]);
	ft_display(info);
	free_info(info);
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac == 2 || (ac == 3 && !ft_strcmp(av[2], "--save")))
		ft_cub3d(ac, av);
	else
		ft_putstr_fd("Error\nusage : cub3D *.cub [--save]\n", 2);
	return (0);
}
