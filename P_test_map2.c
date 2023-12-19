/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_test_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:28:12 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:39:34 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "P_CUBE3D.h"

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	free_t1(char *t1, char *trimmed_char, int return1)
{
	free(t1);
	free(trimmed_char);
	return (return1);
}

int	element_of_map(char *line)
{
	char	*trimmed_char;
	char	*t1;
	int		i;

	i = 0;
	t1 = ft_strtrim(line, "\n");
	trimmed_char = ft_strtrim(t1, " ");
	if (!trimmed_char[0])
		return (free_t1(t1, trimmed_char, 0));
	while (trimmed_char[i])
	{
		if (trimmed_char[i] != '1' && trimmed_char[i] != '0'
			&& trimmed_char[i] != 'W' && trimmed_char[i] != 'E'
			&& trimmed_char[i] != 'S' && trimmed_char[i] != 'N'
			&& trimmed_char[i] != ' ')
			return (free_t1(t1, trimmed_char, 0));
		i++;
	}
	return (free_t1(t1, trimmed_char, 1));
}
