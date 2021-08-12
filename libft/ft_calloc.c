/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:42:49 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/22 18:27:46 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	octets;

	octets = size * count;
	ret = malloc(octets);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, octets));
}
