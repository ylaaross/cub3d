/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_cube3d1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:22:43 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:37:42 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

void	callocate(char ***d2, int size, int wid)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*d2)[i] = ft_calloc(wid + 1, sizeof(char));
		i++;
	}
}

char	**convertto_arr(t_file *o)
{
	int		i;
	int		j;
	int		size;
	int		wid;
	char	**d2;

	init_convert(&size, o, &i, &j);
	d2 = ft_calloc(size + 1, sizeof(char **));
	wid = width(o);
	callocate(&d2, size, wid);
	i = 0;
	while (o)
	{
		j = 0;
		while (o->line[j])
		{
			d2[i][j] = o->line[j];
			j++;
		}
		i++;
		o = o->next;
	}
	return (d2);
}

int	detect_line_element(char *ch)
{
	int	i;

	i = 0;
	while (ch[i])
	{
		if (ch[i] == '1' || ch[i] == '0' || ch[i] == 'W' || ch[i] == 'E'
			|| ch[i] == 'S' || ch[i] == 'N')
			return (1);
		i++;
	}
	return (0);
}

int	find_map(char *f)
{
	if ((!ft_strstr_2(f, "EA") && !ft_strstr_2(f, "SO") && !ft_strstr_2(f, "WE")
			&& !ft_strstr_2(f, "NO") && !ft_strstr_2(f, "C") && !ft_strstr_2(f,
				"F")) && detect_line_element(f))
		return (1);
	return (0);
}

int	first_line(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (find_map(t[i]))
			return (i);
		i++;
	}
	return (-1);
}
