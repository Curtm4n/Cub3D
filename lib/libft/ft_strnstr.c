/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:57:04 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/28 21:38:35 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		a = 0;
		while ((i + a) < len && needle[a] && haystack[i + a] == needle[a])
			a++;
		if (needle[a] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
