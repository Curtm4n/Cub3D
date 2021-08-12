/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:25:31 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:39:59 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_find_start(char const *s1, char const *set)
{
	int	i;
	int	a;

	i = 0;
	while (s1[i])
	{
		a = 0;
		while (set[a])
		{
			if (set[a] == s1[i])
				break ;
			a++;
		}
		if (set[a] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int	i;
	int	a;

	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		a = 0;
		while (set[a])
		{
			if (set[a] == s1[i])
				break ;
			a++;
		}
		if (set[a] == '\0')
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim2(char const *s1, int start, int end)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = end - start + 2;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (end <= start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_strtrim2(s1, start, end);
	return (str);
}
