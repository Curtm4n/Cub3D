/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:32:20 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/26 19:10:30 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_rest(char *buff, char **line)
{
	int	a;
	int	i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			break ;
	buff[i] = '\0';
	*line = malloc(i + 1);
	if (!*line)
		return (-1);
	a = -1;
	while (++a <= i)
		(*line)[a] = buff[a];
	a = 0;
	while (buff[++i])
	{
		buff[a] = buff[i];
		a++;
	}
	buff[a] = '\0';
	return (1);
}

int	get_line(char *buff, char **line, char *str)
{
	if (ft_get_rest(buff, line) == -1)
		return (-1);
	if (str)
	{
		*line = ft_strjoin_free(str, *line, 1);
		if (!*line)
			return (-1);
	}
	return (1);
}

int	ft_read_line(int fd, char *buff, char **line)
{
	char	*str;
	int		r;

	str = NULL;
	if (buff && buff[0] != '\0')
	{
		str = ft_substr_free(buff, 0, ft_strlen(buff), 1);
		if (!str)
			return (-1);
	}
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buff[r] = '\0';
		if (check_line(buff) >= 0)
			return (get_line(buff, line, str));
		str = ft_strjoin_free(str, buff, 0);
		if (!str)
			return (-1);
	}
	*line = str;
	return (r);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (check_line(buff) >= 0)
		return (ft_get_rest(buff, line));
	ret = ft_read_line(fd, buff, line);
	if (ret == -1)
		return (-1);
	if (*line == NULL)
	{
		*line = malloc(1);
		if (!*line)
			return (-1);
		*line[0] = '\0';
	}
	if (ret == 0)
		buff[0] = '\0';
	return (ret);
}
