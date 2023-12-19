/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_cube3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:23:16 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/19 19:37:48 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

int	first_last_line_t(char *ch)
{
	int	i;

	i = 0;
	while (ch[i])
	{
		if (ch[i] == '0' || ch[i] == 'N')
			return (1);
		i++;
	}
	return (0);
}

int	test_if_vide(char **map)
{
	int	i;
	int	maxhight;

	maxhight = strlen_2d(map);
	if (last_char(map[maxhight - 1]))
		return (1);
	i = 0;
	while (i < maxhight)
	{
		if (empty_line(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	duplicatedor_less_test(t_map_struct *map_struct, char *ch)
{
	int	count;

	count = 0;
	while (map_struct)
	{
		if (!ft_strcmp(map_struct->element_type, ch))
			count++;
		map_struct = map_struct->next;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	duplicated_less_elements(t_map_struct *map_struct)
{
	if (duplicatedor_less_test(map_struct, "EA")
		|| duplicatedor_less_test(map_struct, "SO")
		|| duplicatedor_less_test(map_struct, "WE")
		|| duplicatedor_less_test(map_struct, "NO"))
		return (1);
	return (0);
}

int	count_rgb(t_range *r, char c)
{
	int	count;

	count = 0;
	while (r)
	{
		if (r->identifiant == c)
			count++;
		r = r->next;
	}
	if (count != 1)
		return (1);
	return (0);
}
