/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:38:12 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:45:56 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "P_get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		ls1;
	size_t		ls2;
	size_t		i;
	char		*p;

	p = 0;
	i = 0;
	ls1 = ft_strlenp(s1);
	ls2 = ft_strlenp(s2);
	p = (char *)malloc(ls1 + ls2 + 1);
	if (p == 0)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(p, s1, ls1 + 1);
	ft_strlcat(p, s2, ls1 + ls2 + 1);
	free(s1);
	return (p);
}

int	check(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	initialise(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
}

char	*devide(char	*line, char *rest, int size)
{
	int		i[3];
	char	*new_line;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (line[i[0]])
	{
		if (line[i[0]] == '\n')
			break ;
		i[0] = i[0] + 1;
	}
	if (line[i[0]] == '\n')
		i[0] = i[0] + 1;
	new_line = ft_substr(line, 0, i[0]);
	initialise(rest, size);
	if (line[i[0]])
	{
		while (line[i[0]])
			rest[(i[1])++] = line[(i[0])++];
		rest[i[1]] = 0;
	}
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	int			sread;
	char		*line;

	sread = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 2 || fd == 1)
		return (0);
	initialise(buffer, BUFFER_SIZE + 1);
	line = ft_calloc(1, 1);
	line = ft_strjoin(line, rest);
	while (sread > 0 && check(line))
	{
		sread = read(fd, buffer, BUFFER_SIZE);
		if (sread == -1 || (sread == 0 && *line == 0))
		{
			initialise(rest, BUFFER_SIZE);
			free(line);
			return (0);
		}
		buffer[sread] = 0;
		line = ft_strjoin(line, buffer);
	}
	return (devide (line, rest, BUFFER_SIZE));
}
