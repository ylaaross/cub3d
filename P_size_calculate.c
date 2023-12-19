/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_size_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:05:40 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:47:28 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

int	strlen_2d(char **mline)
{
	int	i;

	i = 0;
	while (mline[i])
		i++;
	return (i);
}

int	strlen_2d_st(t_file *o)
{
	int	count;

	count = 0;
	while (o)
	{
		count++;
		o = o->next;
	}
	return (count);
}

int	width(t_file *o)
{
	int	w;
	int	max_width;

	w = 0;
	max_width = 0;
	while (o)
	{
		w = ft_strlenp(o->line);
		if (max_width < w)
			max_width = w;
		o = o->next;
	}
	return (max_width);
}
