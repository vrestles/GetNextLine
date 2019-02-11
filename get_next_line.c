/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:42:39 by vrestles          #+#    #+#             */
/*   Updated: 2018/12/10 20:01:05 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

static int		find_len_line(char *str, char c)
{
	int	n;
	int	flag;

	n = 0;
	flag = 0;
	while (*str)
	{
		if (*str == c)
		{
			flag = 1;
			break ;
		}
		str++;
		n++;
	}
	if (*str == c)
		flag = 1;
	return ((flag == 1) ? n : -1);
}

static int		get_end(char **next, char **line)
{
	int		len;
	char	*tmp;

	if (ft_strchr(*next, '\n'))
	{
		len = find_len_line(*next, '\n');
		if ((*line = ft_strsub(*next, 0, len)) == NULL)
			free(*next);
		if (*line == NULL)
			return (-1);
		tmp = ft_strdup(*next + len + 1);
		free(*next);
		CHECK(tmp);
		*next = tmp;
		if (**next == '\0')
			ft_strdel(next);
	}
	else
	{
		*line = ft_strdup(*next);
		ft_strdel(next);
		CHECK(*line);
	}
	return (1);
}

static int		check_errors(int fd, char *buffer, char **line)
{
	if (fd < 0 || read(fd, buffer, 0) < 0 || line == NULL)
	{
		free(buffer);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buffer;
	static char		*next;
	char			*tmp;

	buffer = ft_strnew((size_t)BUFF_SIZE);
	CHECK(buffer);
	if (check_errors(fd, buffer, line) == 1)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (next == NULL)
			next = ft_strnew(0);
		tmp = ft_strjoin(next, buffer);
		free(next);
		CHECK(tmp);
		next = tmp;
		if (ft_strchr(buffer, '\n') || ret < BUFF_SIZE)
			break ;
		ft_strclr(buffer);
	}
	if ((!next || next[0] == '\0') && ret == 0)
		return (0);
	free(buffer);
	return (get_end(&next, line));
}
