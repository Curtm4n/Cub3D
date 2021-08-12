/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 23:58:38 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/22 18:25:08 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	len_src;

	i = 0;
	a = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	while (dest[i] && i < size)
		i++;
	while (src[a] && a < (size - i - 1) && i != size)
	{
		dest[i + a] = src[a];
		a++;
	}
	if (i < size)
		dest[i + a] = '\0';
	return (len_src + i);
}
