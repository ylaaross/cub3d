/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_store1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:27:52 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:28:18 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

void	fifo(t_file **head, char *line)
{
	t_file	*t;

	t = 0;
	if (*head == 0)
	{
		*head = malloc(sizeof(t_file));
		(*head)->line = ft_strdup(line);
		free(line);
		(*head)->next = 0;
	}
	else
	{
		t = *head;
		while (t->next)
			t = t->next;
		t->next = malloc(sizeof(t_file));
		t->next->line = ft_strdup(line);
		free(line);
		t->next->next = 0;
	}
}

void	file_read(t_file **f, int fd)
{
	char	*line;
	int		i;

	line = 0;
	i = 1;
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (line)
		fifo(f, line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			fifo(f, line);
		i++;
	}
	close(fd);
}
