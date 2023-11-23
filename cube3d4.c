/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:22:20 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 17:22:21 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	detect_inprotected_space(char **map)
{
	int	j;
	int	i;
	int	m;

	init_detect(&i, &j, &m);
	last_line(map, &m);
	if (first_last_line_t(map[m]) || first_last_line_t(map[0]))
		return (1);
	while (i < m)
	{
		j = 0;
		while (map[i][j])
		{
			if (map_element(map[i][j]) && compare_element(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// 0 pour les espacesvides, 1 pour les murs, et N,S,E ou W
int	element_intru(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
					&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
					&& map[i][j] != ' ' && map[i][j] != '\n'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_player(char **map)
{
	int	i;
	int	j;
	int	count;
	int	tab;

	i = 0;
	j = 0;
	tab = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'N')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1 || count == 0)
		return (0);
	return (1);
}

void	t_tabcheck(t_file *f)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (f)
	{
		i = 0;
		while (f->line[i])
		{
			if (f->line[i] == 9 || f->line[i] == 11)
			{
				printf("*");
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}
		f = f->next;
	}
}

void	print_err(void)
{
	write(2, "Error\n", 6);
	while (1)
		;
	exit(1);
}
