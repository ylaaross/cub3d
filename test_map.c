/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:27:28 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/22 19:28:06 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	last_char(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	if (p[i - 1] == '\n')
		return (1);
	return (0);
}

int	search_eline(char **p)
{
	int	i;

	i = 1;
	if (!p)
		return (0);
	while (p[i])
	{
		if (empty_line(p[i]) && element_of_map(p[i - 1]))
			return (1);
		i++;
	}
	return (last_char(p[i - 1]));
}

void	in_test_line(int *i, int *j, int *count, int *not_empty)
{
	*i = 0;
	*j = 0;
	*count = 0;
	*not_empty = 0;
}

int	test_lines(char **p)
{
	int	i;
	int	j;
	int	not_empty;
	int	count;

	in_test_line(&i, &j, &count, &not_empty);
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] != ' ' && p[i][j] != '\n')
				not_empty = 1;
			j++;
		}
		if (not_empty)
		{
			count++;
			not_empty = 0;
		}
		i++;
	}
	return (count);
}
