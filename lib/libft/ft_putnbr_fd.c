/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:15:42 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:38:47 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_display_nb(long n, int fd)
{
	int		i;
	char	tab[10];

	i = 0;
	while (n != 0)
	{
		tab[i] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &tab[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n == 0)
		write(fd, "0", 1);
	if (nb != 0)
		ft_display_nb(n, fd);
}
