/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:27:39 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/22 18:02:16 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		value;

	i = 0;
	if (i == n)
		return (0);
	while (s1[i] == s2[i])
	{
		if ((s1[i] == '\0' && s2[i] == '\0') || i == n - 1)
			return (0);
		i++;
	}
	value = s1[i] - s2[i];
	if (s1[i] < 0 || s2[i] < 0)
		value = -value;
	return (value);
}
