/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:17:29 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/24 19:07:04 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	int		i;
	int		a;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_const_strlen(s1);
	len_2 = ft_const_strlen(s2);
	ret = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	a = -1;
	while (s2[++a])
		ret[i + a] = s2[a];
	ret[i + a] = '\0';
	return (ret);
}
