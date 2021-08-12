/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:54:01 by curtman           #+#    #+#             */
/*   Updated: 2021/08/05 16:39:14 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_create_ver(char *str, char *charset, char *ver)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
			{
				ver[i] = '1';
				break ;
			}
		}
		if (!charset[j])
			ver[i] = '0';
	}
	ver[i] = '\0';
	return (ver);
}

char	**ft_create_strs(char *ver)
{
	int		i;
	int		cptr;
	char	**strs;

	i = -1;
	cptr = 0;
	while (ver[++i])
	{
		if (ver[i] == '0')
		{
			cptr++;
			while (ver[i] == '0' && ver[i + 1])
				i++;
		}
	}
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	strs[i] = 0;
	return (strs);
}

int	ft_create_str(char *ver, char **strs)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = -1;
	while (ver[++j])
	{
		len = 0;
		while (ver[j] == '0')
		{
			len++;
			if (!ver[j + 1])
				break ;
			j++;
		}
		if (len != 0)
		{
			strs[++i] = malloc(sizeof(char) * (len + 1));
			if (!strs[i])
				return (i);
			strs[i][len] = '\0';
		}
	}
	return (-1);
}

char	**ft_fill_strs(char **strs, char *str, char *ver)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ver[i] == '0')
		{
			k = -1;
			while (ver[i] == '0')
			{
				strs[j][++k] = str[i];
				if (!str[i + 1])
					break ;
				i++;
			}
			j++;
		}
	}
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*ver;
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	ver = malloc(sizeof(char) * (i + 1));
	if (!ver || !str)
		return (NULL);
	ver = ft_create_ver(str, charset, ver);
	strs = ft_create_strs(ver);
	if (!strs)
		return (NULL);
	i = ft_create_str(ver, strs) + 1;
	if (i - 1 >= 0)
	{
		while (--i >= 0)
			free(strs[i]);
		free(strs);
		return (NULL);
	}
	free(ver);
	return (ft_fill_strs(strs, str, ver));
}
