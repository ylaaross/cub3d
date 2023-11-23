/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:29:55 by ylaaross          #+#    #+#             */
/*   Updated: 2023/11/23 16:23:31 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUBE3D.h"

int	height_2(char **p, int i)
{
	int	count;

	count = 0;
	while (p[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	max_width2(char **p, int i)
{
	int	j;
	int	w;

	w = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
			j++;
		if (w < j)
			w = j;
		i++;
	}
	return (w);
}

void	copy(char **o, t_all_infos *infos, int i)
{
	int	j;
	int	k;

	k = 0;
	while (o[i])
	{
		j = 0;
		while (o[i][j])
		{
			infos->map_only[k][j] = o[i][j];
			j++;
		}
		k++;
		i++;
	}
}

void	parcour_map(t_all_infos *infos, int *i)
{
	*i = 0;
	while (infos->map[*i])
	{
		if (find_map(infos->map[*i]))
			break ;
		*i = *i + 1;
	}
}

void	mallocate_map(t_all_infos *infos)
{
	int	i;
	int	j;
	int	w;
	int	h;

	j = 0;
	parcour_map(infos, &i);
	if (infos->map[i])
	{
		h = height_2(infos->map, i);
		w = max_width2(infos->map, i);
		infos->map_only = ft_calloc(h + 1, sizeof(char **));
		j = 0;
		while (j < h)
		{
			infos->map_only[j] = ft_calloc(w + 1, sizeof(char));
			j++;
		}
		copy(infos->map, infos, i);
	}
	else
	{
		printf("NO");
		exit(1);
	}
}
