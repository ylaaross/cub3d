/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:23:32 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:25:45 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	max_width3(t_all_infos *infos, int s)
{
	int	i;
	int	width;
	int	wmax;

	i = 0;
	wmax = 0;
	while (i < s)
	{
		width = ft_strlen(infos->map[i]);
		if (width > wmax)
			wmax = width;
		i++;
	}
	return (wmax);
}

void	mallocate_(t_all_infos *infos, int s)
{
	int	i;
	int	w;
	int	j;

	i = 0;
	infos->element_part = ft_calloc(s + 1, sizeof(char **));
	w = max_width3(infos, s);
	while (i < s)
	{
		infos->element_part[i] = ft_calloc(w + 1, sizeof(char));
		i++;
	}
	i = 0;
	while (i < s)
	{
		j = 0;
		while (infos->map[i][j])
		{
			infos->element_part[i][j] = infos->map[i][j];
			j++;
		}
		i++;
	}
}

void	mallocate_element_var(t_all_infos *infos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (infos->map[i])
	{
		if (element_of_map(infos->map[i]))
			break ;
		i++;
	}
	if (i > 0)
		mallocate_(infos, i);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
