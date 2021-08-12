/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:29:48 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:34:43 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_create_alpha(long nb, int sign)
{
	int		i;
	int		a;
	char	*ret;
	char	tab[12];

	i = 0;
	a = 0;
	while (nb > 0)
	{
		tab[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	if (sign == -1)
		tab[i++] = '-';
	tab[i] = '\0';
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	while (i > 0)
		ret[a++] = tab[--i];
	ret[a] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		sign;
	char	*ret;

	nb = n;
	sign = 1;
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	if (nb == 0)
	{
		ret = malloc(2);
		if (!ret)
			return (NULL);
		ret[0] = '0';
		ret[1] = 0;
		return (ret);
	}
	ret = ft_create_alpha(nb, sign);
	return (ret);
}
