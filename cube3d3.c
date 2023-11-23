/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:23:57 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 17:24:25 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	duplicated_rgb(t_range *r)
{
	if (count_rgb(r, 'F') || count_rgb(r, 'C'))
		return (1);
	return (0);
}

void	init_detect(int *i, int *j, int *m)
{
	*i = 1;
	*j = 0;
	*m = 0;
}

void	last_line(char **map, int *m)
{
	while (map[*m])
		*m = *m + 1;
	*m = *m - 1;
}

int	map_element(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	compare_element(char **map, int i, int j)
{
	if (j == 0 || map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i
		- 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j + 1] == 0 || map[i][j
		- 1] == 0 || map[i][j + 1] == 0 || map[i - 1][j] == 0 || map[i
		+ 1][j] == 0 || map[i][j + 1] == '\n' || map[i - 1][j] == '\n' || map[i
		+ 1][j] == '\n')
		return (1);
	return (0);
}
